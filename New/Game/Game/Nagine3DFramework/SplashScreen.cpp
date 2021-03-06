// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "SplashScreen.h"
#include "na3de\include\Utility.h"
#include "GameMenuScreen.h"
using namespace Ogre;

SplashScreen SplashScreen::mSplashScreen;
float count = 0;
void SplashScreen::enter()
{
	
	//mInputDevice = InputManager::getSingletonPtr()->getInputDevice();
	mRoot = Root::getSingletonPtr();

	//should be for Ogre 1.2 createSceneManager(ST_GENERIC);
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC,StringUtil::BLANK);
	mCamera = mSceneMgr->createCamera("SplashScreenCamera");
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
	mViewport->setBackgroundColour(ColourValue(1.0, 1.0, 1.0));
	Utility::InitText();
	//Utility::drawIMG(mSceneMgr, "Background", "SplashScreen.jpg", -1, 1, 1,-1);
	Utility::drawText("Nagine3D Engine\nVersion 1.0\nSplash Screen",12,Vector2(0,0),Ogre::ColourValue(0.5,0,0,1),Ogre::ColourValue::Red);
	mExitGame = false;
}

void SplashScreen::exit()
{
	mSceneMgr->clearScene();
        //!! Note: This is supposed to be mSceneMgr->destroyAllCameras(); for CVS head
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void SplashScreen::pause()
{
}

void SplashScreen::resume()
{
}

bool SplashScreen::frameStarted(const FrameEvent& evt)
{
	printf("%f\n", count);
	count += 0.1;
	//mKeyboard->capture();
	return true;
}

bool SplashScreen::frameEnded(const FrameEvent& evt)
{
	if (count >= 100) changeState(GameMenuScreen::getInstance());
	if (mExitGame)
		return false;

	return true;
}

void SplashScreen::keyPressed( const OIS::KeyEvent &e ) {
}

void SplashScreen::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {

        mExitGame = true;
    }
	
}

void SplashScreen::mouseMoved( const OIS::MouseEvent &e ) {
}

void SplashScreen::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void SplashScreen::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}