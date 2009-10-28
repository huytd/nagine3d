// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#ifndef GameMenuScreen_H
#define GameMenuScreen_H

#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>

#include "na3de\include\GameState.h"

class GameMenuScreen : public GameState
{
public:
	void enter();
	void exit();

	void pause();
	void resume();

	bool frameStarted(const Ogre::FrameEvent& evt);
	bool frameEnded(const Ogre::FrameEvent& evt);

	void keyPressed( const OIS::KeyEvent &e );
    void keyReleased( const OIS::KeyEvent &e );

    void mouseMoved( const OIS::MouseEvent &e );
    void mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    void mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

	static GameMenuScreen* getInstance() { return &mGameMenuScreen; }
protected:
	GameMenuScreen() { }

	Ogre::Root *mRoot;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Viewport* mViewport;
	Ogre::Camera* mCamera;
	//OIS::Keyboard* mKeyboard;

	bool mExitGame;
private:
	static GameMenuScreen mGameMenuScreen;
};

#endif