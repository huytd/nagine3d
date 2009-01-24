#ifndef _OGREHEAD_H_
#define _OGREHEAD_H_

#include <Ogre.h>
#include <iostream>

class OgreHead
{
public:
	OgreHead(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS);
	void lookatme();
private:
	Ogre::Root *mRoot;
	Ogre::SceneManager *mSceneMgr;
};

#endif