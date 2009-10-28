// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "OptionScreen.h"
#include "na3de\include\Utility.h"

using namespace Ogre;

OptionScreen OptionScreen::mOptionScreen;

void OptionScreen::enter()
{
	
	//mInputDevice = InputManager::getSingletonPtr()->getInputDevice();
	mRoot = Root::getSingletonPtr();

	//should be for Ogre 1.2 createSceneManager(ST_GENERIC);
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC,StringUtil::BLANK);
	mCamera = mSceneMgr->createCamera("IntroCamera");
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
	mViewport->setBackgroundColour(ColourValue(1.0, 1.0, 1.0));
	Utility::InitText();
	//Utility::drawIMG(mSceneMgr, "Background", "OptionScreen.jpg", -1, 1, 1,-1);
	Utility::drawText("Nagine3D Engine\nVersion 1.0\nOption",12);
	mExitGame = false;
}

void OptionScreen::exit()
{
	
	mSceneMgr->clearScene();
        //!! Note: This is supposed to be mSceneMgr->destroyAllCameras(); for CVS head
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void OptionScreen::pause()
{
}

void OptionScreen::resume()
{
}

bool OptionScreen::frameStarted(const FrameEvent& evt)
{
	//mKeyboard->capture();
	return true;
}

bool OptionScreen::frameEnded(const FrameEvent& evt)
{
	if (mExitGame)
		return false;

	return true;
}

void OptionScreen::keyPressed( const OIS::KeyEvent &e ) {
}

void OptionScreen::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {

        mExitGame = true;
    }
	
}

void OptionScreen::mouseMoved( const OIS::MouseEvent &e ) {
}

void OptionScreen::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void OptionScreen::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}