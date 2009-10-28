// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "HelpAboutScreen.h"
#include "na3de\include\Utility.h"

using namespace Ogre;

HelpAboutScreen HelpAboutScreen::mHelpAboutScreen;

void HelpAboutScreen::enter()
{
	
	//mInputDevice = InputManager::getSingletonPtr()->getInputDevice();
	mRoot = Root::getSingletonPtr();

	//should be for Ogre 1.2 createSceneManager(ST_GENERIC);
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC,StringUtil::BLANK);
	mCamera = mSceneMgr->createCamera("IntroCamera");
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
	mViewport->setBackgroundColour(ColourValue(1.0, 1.0, 1.0));
	Utility::InitText();
	//Utility::drawIMG(mSceneMgr, "Background", "HelpAboutScreen.jpg", -1, 1, 1,-1);
	Utility::drawText("Nagine3D Engine\nVersion 1.0\nHelp and About",12);
	mExitGame = false;
}

void HelpAboutScreen::exit()
{
	
	mSceneMgr->clearScene();
        //!! Note: This is supposed to be mSceneMgr->destroyAllCameras(); for CVS head
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void HelpAboutScreen::pause()
{
}

void HelpAboutScreen::resume()
{
}

bool HelpAboutScreen::frameStarted(const FrameEvent& evt)
{
	//mKeyboard->capture();
	return true;
}

bool HelpAboutScreen::frameEnded(const FrameEvent& evt)
{
	if (mExitGame)
		return false;

	return true;
}

void HelpAboutScreen::keyPressed( const OIS::KeyEvent &e ) {
}

void HelpAboutScreen::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {

        mExitGame = true;
    }
	
}

void HelpAboutScreen::mouseMoved( const OIS::MouseEvent &e ) {
}

void HelpAboutScreen::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void HelpAboutScreen::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}