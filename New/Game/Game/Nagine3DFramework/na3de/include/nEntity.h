// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#ifndef _NENTITY_H_
#define _NENTITY_H_


#include <Ogre.h>
#include <iostream>

class nEntity: public Ogre::FrameListener
{
public:
	virtual bool frameStarted(const Ogre::FrameEvent& evt) = 0;
	virtual bool frameEnded(const Ogre::FrameEvent& evt) = 0;
	virtual void Update() = 0;
	
	void setName(Ogre::String name) {mName = name;};
	void setNode(Ogre::SceneNode* node) {mNode = node;};
	void setRoot(Ogre::Root* root) {mRoot = root;};
	void setSceneMgr(Ogre::SceneManager* smg) {mSceneMgr = smg; };
	void setEntity(Ogre::Entity* ent) {mEntity = ent;};

	Ogre::Root *getRoot() {return mRoot;};
	Ogre::SceneManager *getSceneMgr() {return mSceneMgr;};
	Ogre::SceneNode *getNode() {return mNode;};
	Ogre::Entity *getMEntity() {return mEntity;};
	Ogre::String getName() { return mName; };

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