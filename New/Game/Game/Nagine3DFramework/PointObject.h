// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

//Highest level of pointobject in Nagine3D
#ifndef _PointObject_H_
#define _PointObject_H

#include <Ogre.h>
#include "na3de\include\nEntity.h"

class PointObject: public nEntity
{
public:
	PointObject(){};
	PointObject(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS);
	
	bool frameStarted(const Ogre::FrameEvent& evt);
	bool frameEnded(const Ogre::FrameEvent& evt);
	void Update();

	void setRadius(float oRad) { pRadius = oRad; };
	float getRadius() { return pRadius; };
	void setName(Ogre::String oName) { pName = oName; };
	Ogre::String getName() { return pName; };
	void setPosition(Ogre::Vector3 oPos) { pPosition = oPos; };
	Ogre::Vector3 getPosition() { return pPosition; };
	bool hitTest(Ogre::Vector3 oPos) { 
		if (getPosition().distance(oPos) <= getRadius())
			return true;
		return false;
	};

private:
	float pRadius;
	Ogre::Vector3 pPosition;
	Ogre::String pName;
};

#endif