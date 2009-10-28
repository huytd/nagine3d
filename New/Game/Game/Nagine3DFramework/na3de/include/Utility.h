// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".
// and grabbed some cool stuff from Ogre3D Wiki, thank everybody!
#pragma once

#include "precomp.h"

#include <Ogre.h>
#include <OIS/OIS.h>

#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>
#include <OgreTextAreaOverlayElement.h>
#include <OgreFontManager.h>
#include "ogre2dmgr.h"

using namespace Ogre;

class Utility
{
private:
	int screenWidth;
	int screenHeight;
	static OverlayManager* overlayManager;
	static OverlayContainer* panel;
	static Overlay* overlay;
	static Ogre2dManager* ogre2dManager;
public:
	Utility();
	
public:
	
	void NA3D_API tellScreenW(int sW);
	void NA3D_API tellScreenH(int sH);
	static void NA3D_API drawIMG(Ogre::SceneManager *mSceneMgr, Ogre::String imgName, Ogre::String imgFileName, Ogre::Real x1=-1.0, Ogre::Real y1=1.0, Ogre::Real x2=1.0, Ogre::Real y2=-1.0);
	static void NA3D_API drawText(Ogre::String tText, int tSize = 10, Ogre::Vector2 tPosition = Ogre::Vector2(0,0), Ogre::ColourValue tTopColor = Ogre::ColourValue(0.5, 0.7, 0.5), Ogre::ColourValue tBotColor = Ogre::ColourValue(0.3, 0.5, 0.3));
	static void NA3D_API InitText();
	static void NA3D_API Init2DMgr(SceneManager* mSceneMgr);
	static void NA3D_API Destroy2DMgr();
	static NA3D_API Ogre2dManager* get2DMgr();
};
