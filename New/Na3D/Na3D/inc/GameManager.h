// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#ifndef GameManager_H
#define GameManager_H

#include "precomp.h"
#include <vector>
#include <Ogre.h>
#include "precomp.h"
#include <OgreSingleton.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>
#include "InputManager.h"

class GameState;

class GameManager : public Ogre::FrameListener,	public Ogre::Singleton<GameManager>,public OIS::KeyListener, OIS::MouseListener
{
public:
	NA3D_API GameManager();
	~GameManager();
	void NA3D_API start(GameState* state);
	void NA3D_API changeState(GameState* state);
	void NA3D_API pushState(GameState* state);
	void NA3D_API popState();
	static NA3D_API GameManager& getSingleton(void);
	static NA3D_API GameManager* getSingletonPtr(void);
protected:
	Ogre::Root* mRoot;
	Ogre::RenderWindow* mRenderWindow;

	void NA3D_API setupResources(void);
	bool NA3D_API configure(void);

	bool NA3D_API frameStarted(const Ogre::FrameEvent& evt);
	bool NA3D_API frameEnded(const Ogre::FrameEvent& evt);
private:
	bool NA3D_API keyPressed( const OIS::KeyEvent &e );
    bool NA3D_API keyReleased( const OIS::KeyEvent &e );

    bool NA3D_API mouseMoved( const OIS::MouseEvent &e );
    bool NA3D_API mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool NA3D_API mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    InputManager       *mInputMgr;
	std::vector<GameState*> mStates;
};

#endif