// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "InGameScreen.h"
#include "na3de\include\Utility.h"
#include "WoBoy.h"

using namespace Ogre;

InGameScreen InGameScreen::mInGameScreen;
WoBoySO* wo;

void InGameScreen::enter()
{
	
	//mInputDevice = InputManager::getSingletonPtr()->getInputDevice();
	mRoot = Root::getSingletonPtr();

	//should be for Ogre 1.2 createSceneManager(ST_GENERIC);
	mSceneMgr = mRoot->createSceneManager(ST_GENERIC,StringUtil::BLANK);
	mCamera = mSceneMgr->createCamera("IntroCamera");
	mViewport = mRoot->getAutoCreatedWindow()->addViewport(mCamera);


	mViewport->setBackgroundColour(ColourValue(1.0, 1.0, 1.0));
	Utility::InitText();
	//Utility::drawIMG(mSceneMgr, "Background", "InGameScreen.jpg", -1, 1, 1,-1);
	Utility::drawText("Nagine3D Engine\nVersion 1.0\nIn Game",12,Vector2(0,0),Ogre::ColourValue(0.5,0,0,1),Ogre::ColourValue::Red);
	mExitGame = false;

	mSceneMgr->setSkyBox(true, "SkyboxE");

	wo = new WoBoySO("wo1", mSceneMgr);
	wo->setPosition(Vector3(5, 0, 9));
	wo->getNode()->scale(0.2,0.2,0.2);
	wo->getNode()->yaw(Radian(180));
	mCamera->setPosition(20,0,120);
	mCamera->lookAt(wo->getPosition());
	/*
	Entity *ent2 = mSceneMgr->createEntity( "Robot2", "ninja.mesh" );
	    
	SceneNode *node2 = mSceneMgr->getRootSceneNode()->createChildSceneNode( "RobotNode2", Vector3( 5, 0, 9 ) );
        node2->attachObject( ent2 );
		node2->scale(0.05,0.05,0.05);
	*/

	
	
	/*so = new StaticObject();
	so->setName("Land_StaticObject");
	so->createStaticObject(mSceneMgr,"land.mesh");*/
}

void InGameScreen::exit()
{
	
	mSceneMgr->clearScene();
        //!! Note: This is supposed to be mSceneMgr->destroyAllCameras(); for CVS head
	mRoot->getAutoCreatedWindow()->removeAllViewports();
}

void InGameScreen::pause()
{
}

void InGameScreen::resume()
{
}

bool InGameScreen::frameStarted(const FrameEvent& evt)
{
	//if (lnd->getNode()->isInSceneGraph()) printf("----------\n%f - %f - %f\n", lnd->getPosition().x, lnd->getPosition().y, lnd->getPosition().z);
	//mKeyboard->capture();
	return true;
}

bool InGameScreen::frameEnded(const FrameEvent& evt)
{
	if (mExitGame)
		return false;

	return true;
}

void InGameScreen::keyPressed( const OIS::KeyEvent &e ) {
}

void InGameScreen::keyReleased( const OIS::KeyEvent &e ) {
    if( e.key == OIS::KC_ESCAPE ) {

        mExitGame = true;
    }
	
}

void InGameScreen::mouseMoved( const OIS::MouseEvent &e ) {
}

void InGameScreen::mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
}

void InGameScreen::mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id ) {
    
}