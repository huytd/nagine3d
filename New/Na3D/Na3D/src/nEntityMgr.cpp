#include "stdafx.h"
#include "nEntityMgr.h"

std::list<nEntity*> nEList;

void NA3D_API addEntity(nEntity* cen) {nEList.push_back(cen); }

template< class ENT_TYPE >
nEntity* nEntityMgr::createEntity(Ogre::String name, Ogre::SceneNode* node, Ogre::Entity* enti, Ogre::Root* ro, Ogre::SceneManager* smg){
	ENT_TYPE* nType = new ENT_TYPE();
	nType->setEntity(enti);
	nType->setNode(node);
	nType->setName(name);
	nType->setRoot(ro);
	nType->setSceneMgr(smg);
	return nType;
}

nEntity* nEntityMgr::getEntityByName(std::string cName) {
	std::list<nEntity*>::const_iterator i;
	for(i=nEList.begin();i!=nEList.end();i++)
	{
		if (cName == (*i)->getName())
			return *i;
	}
	return 0;
}

void NA3D_API nEntityMgr::Update() {
	std::list<nEntity*>::const_iterator i;
	for(i=nEList.begin();i!=nEList.end();i++)
	{
		(*i)->Update();
	}
}