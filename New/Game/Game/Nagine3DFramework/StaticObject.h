// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#ifndef _StaticObject_H_
#define _StaticObject_H

#include <Ogre.h>
#include "na3de\include\nEntity.h"

class StaticObject: public nEntity
{
public:
	StaticObject(){};
	StaticObject(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS);
	
	virtual bool frameStarted(const Ogre::FrameEvent& evt) = 0;
	virtual bool frameEnded(const Ogre::FrameEvent& evt) = 0;
	virtual void Update() = 0;

	void setName(Ogre::String oName) { sName = oName; };
	Ogre::String getName() { return sName; };
	void setPosition(Ogre::Vector3 oPos) { sPosition = oPos; };
	Ogre::Vector3 getPosition() { return sPosition; };
private:
	Ogre::Vector3 sPosition;
	Ogre::String sName;
};

#endif