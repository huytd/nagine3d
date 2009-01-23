#ifndef _OGREHEAD3_H_
#define _OGREHEAD3_H_

#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>
#include "NGEntity.h"
#include <iostream>

class OgreHead3:public NGEntity
{
public:
	OgreHead3();
	void printName();
	void setRoot(Ogre::Root *mR, Ogre::SceneManager *mS);
private:
	Ogre::Root *mRoot;
	Ogre::SceneManager* mSceneMgr;
};

#endif