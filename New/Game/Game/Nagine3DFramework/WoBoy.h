// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#ifndef _LandWoBoySO_H_
#define _WoBoySO_H

#include <Ogre.h>
#include "na3de\include\nEntity.h"
#include "StaticObject.h"

class WoBoySO: public StaticObject
{
public:
	WoBoySO(Ogre::String name, Ogre::SceneManager* smgr){
		setName(name);
		this->setEntity(smgr->createEntity( name, "Wo.mesh" ));
	    this->setNode(smgr->getRootSceneNode()->createChildSceneNode( name, Vector3( 5, 0, 9 )));
		this->getNode()->attachObject(this->getMEntity());
		this->getNode()->yaw(Degree(180));
	};

	bool frameStarted(const Ogre::FrameEvent& evt){ return true; };
	bool frameEnded(const Ogre::FrameEvent& evt){ return true; };
	void Update(){};
};

#endif