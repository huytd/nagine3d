#include "OgreHead3.h"
#include "ReflectiveFactory.h"
#include "Level1.h"
#include "Utility.h"

using namespace Ogre;

REGISTER_CLASS(OgreHead3);

Ogre::SceneNode* node;

OgreHead3::OgreHead3()
{
	//mSceneMgr = mRoot->getSceneManager(StringUtil::BLANK);
	//printf("Class 1 created\n");
	//Ogre::Entity* ogrehead = mSceneMgr->getEntity("HeadMesh3");
	node = mSceneMgr->getSceneNode("OgreHead3");
	mSceneMgr->getCamera("Camera01")->lookAt(node->getPosition());
	
}

void OgreHead3::setRoot(Ogre::Root *mR, Ogre::SceneManager *mS)
{
	mRoot = mR;
	mSceneMgr = mS;
}

void OgreHead3::printName()
{
	//printf("Class 1 say: Hello\n");
	//Utility::drawTxt("OgName","OgreHead3", node);
}