// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#ifndef _NENTITYMGR_H_
#define _NENTITYMGR_H_

#include "precomp.h"
#include "nEntity.h"
#include <list>
#include <string>
#include <Ogre.h>
class nEntityMgr
{
public:
	void NA3D_API addEntity(nEntity* cen);

	template< class ENT_TYPE >
	nEntity* createEntity(Ogre::String name, Ogre::SceneNode* node, Ogre::Entity* enti, Ogre::Root* ro = 0, Ogre::SceneManager* smg = 0);

	nEntity* getEntityByName(std::string cName);

	void NA3D_API Update();
};

#endif