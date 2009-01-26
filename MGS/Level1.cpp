#include "Level1.h"
#include "IntroState.h"
#include "Utility.h"
#include "DotScene.h"
#include "OgreHead.h"

using namespace Ogre;

Level1 Level1::mLevel1;
SceneNode* worldNode;
CDotScene* myDotScene;
OgreHead* oh;

void Level1::enter()
{
	mRoot = Root::getSingletonPtr();
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC);
	mSceneMgr->setAmbientLight( ColourValue( 1, 1, 1 ) );
	
	worldNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("worldRootNode");
	myDotScene = new CDotScene();
	myDotScene->parseDotScene("test.scene", "General", mSceneMgr, mSceneMgr->getSceneNode("worldRootNode"));

	mCamera = mSceneMgr->getCamera("Camera01");
	
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
	mViewport->setBackgroundColour(ColourValue::Black);

	oh = new OgreHead("HeadMesh3", mRoot, mSceneMgr);
	oh->lookatme();

	mExitGame = false;
}

void Level1::exit()
{
	mSceneMgr->clearScene();
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void Level1::pause()
{
}

void Level1::resume()
{
}

bool Level1::frameStarted(const FrameEvent& evt)
{
	oh->getNode()->yaw(Degree(evt.timeSinceLastFrame * 30));
	return true;
}

bool Level1::frameEnded(const FrameEvent& evt)
{
	if (mExitGame)
		return false;

	return true;
}

void Level1::keyPressed( const OIS::KeyEvent &e ) {
}

void Level1::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {

        mExitGame = true;
    }
	if( e.key == OIS::KC_RETURN ) {

		changeState(IntroState::getInstance());
    }
}

void Level1::mouseMoved( const OIS::MouseEvent &e ) {
}

void Level1::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void Level1::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}