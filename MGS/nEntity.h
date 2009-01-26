#ifndef _NENTITY_H_
#define _NENTITY_H_

#include <Ogre.h>
#include <iostream>

class nEntity: public Ogre::FrameListener
{
public:
	virtual bool frameStarted(const Ogre::FrameEvent& evt) = 0;
	virtual bool frameEnded(const Ogre::FrameEvent& evt) = 0;
protected:
	
	nEntity() {};
//private:
	Ogre::Root *mRoot;
	Ogre::SceneManager *mSceneMgr;
	Ogre::SceneNode *mNode;
	Ogre::Entity *mEntity;
	Ogre::String mName;
};

#endif