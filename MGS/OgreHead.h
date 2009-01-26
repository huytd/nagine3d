//#ifndef _OGREHEAD_H_
//#define _OGREHEAD_H_
//
//#include <Ogre.h>
//#include <iostream>
//
//class OgreHead: public Ogre::FrameListener
//{
//public:
//	OgreHead(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS);
//	virtual bool frameStarted(const Ogre::FrameEvent &evt) { OgreHead::update(evt); return true; };
//	//virtual bool frameEnded(const Ogre::FrameEvent &evt) = 0;
//	void update(const Ogre::FrameEvent& evt);
//	void lookatme();
//private:
//	Ogre::Root *mRoot;
//	Ogre::SceneManager *mSceneMgr;
//};
//
//#endif

#ifndef _OGREHEAD_H_
#define _OGREHEAD_H

#include <Ogre.h>
#include "nEntity.h"

class OgreHead: public nEntity
{
public:
	OgreHead(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS);
	void lookatme();
	bool frameStarted(const Ogre::FrameEvent& evt);
	bool frameEnded(const Ogre::FrameEvent& evt);
	Ogre::SceneNode* getNode();
};

#endif