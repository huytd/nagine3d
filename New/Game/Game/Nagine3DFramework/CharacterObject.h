// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

//Highest level of character in Nagine3D
#ifndef _CharacterObject_H_
#define _CharacterObject_H

#include <Ogre.h>
#include "na3de\include\nEntity.h"

class CharacterObject: public nEntity
{
public:
	CharacterObject(){};
	CharacterObject(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS);
	
	bool frameStarted(const Ogre::FrameEvent& evt);
	bool frameEnded(const Ogre::FrameEvent& evt);
	void Update();

private:
	int HP;
	Ogre::String name;
};

#endif