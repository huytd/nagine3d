#include "OgreHead.h"

using namespace Ogre;

Ogre::SceneNode* ogreNode;
Ogre::Entity* ogreHead;
Ogre::String ogreName;

OgreHead::OgreHead(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS)
{
	ogreName = oName;
	mRoot = mR;
	mSceneMgr = mS;
}

void OgreHead::lookatme()
{
	ogreHead = mSceneMgr->getEntity(ogreName);
	ogreNode = ogreHead->getParentSceneNode();
	mSceneMgr->getCamera("Camera01")->lookAt(ogreNode->getPosition());
}