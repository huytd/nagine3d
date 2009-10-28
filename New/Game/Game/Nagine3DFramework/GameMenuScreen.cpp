// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "GameMenuScreen.h"
#include "na3de\include\Utility.h"
#include <string>
#include <sstream>
#include "InGameScreen.h"

using namespace Ogre;

GameMenuScreen GameMenuScreen::mGameMenuScreen;

std::string float_to_str(float f)
{
std::stringstream stream;
stream << f;
return stream.str();
}

void GameMenuScreen::enter()
{
	
	//mInputDevice = InputManager::getSingletonPtr()->getInputDevice();
	mRoot = Root::getSingletonPtr();

	//should be for Ogre 1.2 createSceneManager(ST_GENERIC);
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC,StringUtil::BLANK);
	mCamera = mSceneMgr->createCamera("MenuIntroCamera");
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);
	mViewport->setBackgroundColour(ColourValue(1.0, 1.0, 1.0));
	Utility::InitText();
	
	//Utility::drawIMG(mSceneMgr, "Background", "\gow1.jpg", -1, 1, 1,-1);
	Utility::drawText("Nagine3D Engine\nVersion 1.0\nGame Menu",12,Vector2(0,0),Ogre::ColourValue(0.5,0,0,1),Ogre::ColourValue::Red);
	Utility::drawText("Press Enter to Start Game",20,Vector2(mRoot->getAutoCreatedWindow()->getWidth()/3,mRoot->getAutoCreatedWindow()->getHeight()/2));
	mExitGame = false;
}

void GameMenuScreen::exit()
{
	
	mSceneMgr->clearScene();
        //!! Note: This is supposed to be mSceneMgr->destroyAllCameras(); for CVS head
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void GameMenuScreen::pause()
{
}

void GameMenuScreen::resume()
{
}

bool GameMenuScreen::frameStarted(const FrameEvent& evt)
{
	//mKeyboard->capture();
	return true;
}

bool GameMenuScreen::frameEnded(const FrameEvent& evt)
{
	if (mExitGame)
		return false;

	return true;
}

void GameMenuScreen::keyPressed( const OIS::KeyEvent &e ) {
}

void GameMenuScreen::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {
        mExitGame = true;
    }
	if( e.key == OIS::KC_RETURN ) {
		changeState(InGameScreen::getInstance());
    }
	
}

void GameMenuScreen::mouseMoved( const OIS::MouseEvent &e ) {
}

void GameMenuScreen::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void GameMenuScreen::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}