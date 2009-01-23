#include <Ogre.h>

#include "GameManager.h"
#include "GameState.h"
#include "OgreConfigFile.h"
#include "Utility.h"

using namespace Ogre;

template<> GameManager* Singleton<GameManager>::ms_Singleton = 0;

GameManager::GameManager()
{
	mRoot = 0;
}

GameManager::~GameManager()
{
	// clean up all the states
	while (!mStates.empty()) {
		mStates.back()->exit();
		mStates.pop_back();
	}
	
	if (mRoot)
		delete mRoot;
}

void GameManager::start(GameState* state)
{
	mRoot = new Root();

	setupResources();

	if (!configure()) return;	
        
	TextureManager::getSingleton().setDefaultNumMipmaps(5);
	ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	mInputMgr = InputManager::getSingletonPtr();
	mInputMgr->initialise(mRenderWindow);

	mInputMgr->addKeyListener( this, "GameManager" );
    mInputMgr->addMouseListener( this, "GameManager" );

	mRoot->addFrameListener(this);

	changeState(state);

	mRoot->startRendering();
}

void GameManager::changeState(GameState* state)
{
	// cleanup the current state
	if ( !mStates.empty() ) {
		mStates.back()->exit();
		mStates.pop_back();
	}

	// store and init the new state
	mStates.push_back(state);
	mStates.back()->enter();
}

void GameManager::pushState(GameState* state)
{
	// pause current state
	if ( !mStates.empty() ) {
		mStates.back()->pause();
	}

	// store and init the new state
	mStates.push_back(state);
	mStates.back()->enter();
}

void GameManager::popState()
{
	// cleanup the current state
	if ( !mStates.empty() ) {
		mStates.back()->exit();
		mStates.pop_back();
	}

	// resume previous state
	if ( !mStates.empty() ) {
		mStates.back()->resume();
	}
}

void GameManager::setupResources(void)
{
	// Load resource paths from config file
        ConfigFile cf;
        cf.load("resources.cfg");

        // Go through all sections & settings in the file
        ConfigFile::SectionIterator seci = cf.getSectionIterator();

        String secName, typeName, archName;
        while (seci.hasMoreElements())
        {
            secName = seci.peekNextKey();
            ConfigFile::SettingsMultiMap *settings = seci.getNext();
            ConfigFile::SettingsMultiMap::iterator i;
            for (i = settings->begin(); i != settings->end(); ++i)
            {
                typeName = i->first;
                archName = i->second;
				#if OGRE_PLATFORM == OGRE_PLATFORM_APPLE
                // OS X does not set the working directory relative to the app,
                // In order to make things portable on OS X we need to provide
                // the loading with it's own bundle path location
                ResourceGroupManager::getSingleton().addResourceLocation(
                    String(macBundlePath() + "/" + archName), typeName, secName);
			#else
                ResourceGroupManager::getSingleton().addResourceLocation(
                    archName, typeName, secName);
			#endif
            }
        }
}

bool GameManager::configure(void)
{
	// load config settings from ogre.cfg
	if (!mRoot->restoreConfig())
	{
		// if there is no config file, show the configuration dialog
		if (!mRoot->showConfigDialog())
		{
			return false;
		}
	}

	// initialise and create a default rendering window
	Utility* uti = new Utility();
	mRenderWindow = mRoot->initialise(true, "Nagine3D");
	uti->tellScreenW(mRenderWindow->getWidth());
	uti->tellScreenH(mRenderWindow->getHeight());
	return true;
}

bool GameManager::frameStarted(const FrameEvent& evt)
{
	mInputMgr->capture();
	return mStates.back()->frameStarted(evt);
}

bool GameManager::frameEnded(const FrameEvent& evt)
{
	// call frameEnded of current state
	return mStates.back()->frameEnded(evt);
}

GameManager* GameManager::getSingletonPtr(void)
{
	return ms_Singleton;
}

GameManager& GameManager::getSingleton(void)
{  
	assert(ms_Singleton);
	return *ms_Singleton;
}

bool GameManager::keyPressed( const OIS::KeyEvent &e ) {
    // Call keyPressed of current state
    mStates.back()->keyPressed( e );

    return true;
}

bool GameManager::keyReleased( const OIS::KeyEvent &e ) {
    // Call keyReleased of current state
    mStates.back()->keyReleased( e );

    return true;
}

bool GameManager::mouseMoved( const OIS::MouseEvent &e ) {
    // Call mouseMoved of current state
    mStates.back()->mouseMoved( e );

    return true;
}

bool GameManager::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    // Call mousePressed of current state
    mStates.back()->mousePressed( e, id );

    return true;
}

bool GameManager::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    // Call mouseReleased of current state
    mStates.back()->mouseReleased( e, id );

    return true;
}