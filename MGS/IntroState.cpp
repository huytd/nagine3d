#include "IntroState.h"
#include "Level1.h"
#include "Utility.h"

using namespace Ogre;

IntroState IntroState::mIntroState;

void IntroState::enter()
{
	//mInputDevice = InputManager::getSingletonPtr()->getInputDevice();
	mRoot = Root::getSingletonPtr();

	//should be for Ogre 1.2 createSceneManager(ST_GENERIC);
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC,StringUtil::BLANK);
	mCamera = mSceneMgr->createCamera("IntroCamera");
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
	mViewport->setBackgroundColour(ColourValue(1.0, 1.0, 1.0));

	Utility::drawIMG(mSceneMgr, "Background", "BeachStones.jpg");

	mExitGame = false;
}

void IntroState::exit()
{
	mSceneMgr->clearScene();
        //!! Note: This is supposed to be mSceneMgr->destroyAllCameras(); for CVS head
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void IntroState::pause()
{
}

void IntroState::resume()
{
}

bool IntroState::frameStarted(const FrameEvent& evt)
{
	//mKeyboard->capture();
	return true;
}

bool IntroState::frameEnded(const FrameEvent& evt)
{
	if (mExitGame)
		return false;

	return true;
}

void IntroState::keyPressed( const OIS::KeyEvent &e ) {
}

void IntroState::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {

        mExitGame = true;
    }
	if( e.key == OIS::KC_RETURN ) {

		changeState(Level1::getInstance());
    }
}

void IntroState::mouseMoved( const OIS::MouseEvent &e ) {
}

void IntroState::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void IntroState::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}