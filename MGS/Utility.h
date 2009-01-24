#pragma once
#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>

using namespace Ogre;

class Utility
{
private:
	int screenWidth;
	int screenHeight;
public:
	Utility();
public:
	//static void drawTxt(Ogre::String tName, Ogre::UTFString tText, Ogre::SceneNode *tNode, Ogre::Real tSize=5.0f , Ogre::Real tHeight=20.0f);
	static Ogre::UTFString ConvertToUTF(Ogre::String String);
	void tellScreenW(int sW);
	void tellScreenH(int sH);
	static void drawIMG(Ogre::SceneManager *mSceneMgr, Ogre::String imgName, Ogre::String imgFileName, Ogre::Real x1=-1.0, Ogre::Real y1=1.0, Ogre::Real x2=1.0, Ogre::Real y2=-1.0);

};
