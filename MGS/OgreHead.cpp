#include "OgreHead.h"

using namespace Ogre;

/*Ogre::SceneNode* ogreNode;
Ogre::Entity* ogreHead;
Ogre::String ogreName;*/
#define CUSTOM_SHININESS 1
#define CUSTOM_DIFFUSE 2
#define CUSTOM_SPECULAR 3

OgreHead::OgreHead(Ogre::String oName, Ogre::Root *mR, Ogre::SceneManager *mS)
{
	mName = oName;
	mRoot = mR;
	mSceneMgr = mS;
}

void OgreHead::lookatme()
{
	/*ogreHead = mSceneMgr->getEntity(ogreName);
	ogreNode = ogreHead->getParentSceneNode();
	mSceneMgr->getCamera("Camera01")->lookAt(ogreNode->getPosition());*/
	Light* l = mSceneMgr->createLight("MainLight");

	mEntity = mSceneMgr->getEntity(mName);
	
	// Set common material, but define custom parameters to change colours
        // See Example-Advanced.material for how these are finally bound to GPU parameters
        SubEntity* sub;
        // eyes
        sub = mEntity->getSubEntity(0);
        sub->setMaterialName("Examples/CelShading");
        sub->setCustomParameter(CUSTOM_SHININESS, Vector4(35.0f, 0.0f, 0.0f, 0.0f));
        sub->setCustomParameter(CUSTOM_DIFFUSE, Vector4(1.0f, 0.3f, 0.3f, 1.0f));
        sub->setCustomParameter(CUSTOM_SPECULAR, Vector4(1.0f, 0.6f, 0.6f, 1.0f));
        // skin
        sub = mEntity->getSubEntity(1);
        sub->setMaterialName("Examples/CelShading");
        sub->setCustomParameter(CUSTOM_SHININESS, Vector4(10.0f, 0.0f, 0.0f, 0.0f));
        sub->setCustomParameter(CUSTOM_DIFFUSE, Vector4(0.0f, 0.5f, 0.0f, 1.0f));
        sub->setCustomParameter(CUSTOM_SPECULAR, Vector4(0.3f, 0.5f, 0.3f, 1.0f));
        // earring
        sub = mEntity->getSubEntity(2);
        sub->setMaterialName("Examples/CelShading");
        sub->setCustomParameter(CUSTOM_SHININESS, Vector4(25.0f, 0.0f, 0.0f, 0.0f));
        sub->setCustomParameter(CUSTOM_DIFFUSE, Vector4(1.0f, 1.0f, 0.0f, 1.0f));
        sub->setCustomParameter(CUSTOM_SPECULAR, Vector4(1.0f, 1.0f, 0.7f, 1.0f));
        // teeth
        sub = mEntity->getSubEntity(3);
        sub->setMaterialName("Examples/CelShading");
        sub->setCustomParameter(CUSTOM_SHININESS, Vector4(20.0f, 0.0f, 0.0f, 0.0f));
        sub->setCustomParameter(CUSTOM_DIFFUSE, Vector4(1.0f, 1.0f, 0.7f, 1.0f));
        sub->setCustomParameter(CUSTOM_SPECULAR, Vector4(1.0f, 1.0f, 1.0f, 1.0f));

	mNode = mEntity->getParentSceneNode();
	mSceneMgr->getCamera("Camera01")->lookAt(mNode->getPosition());
	
}

Ogre::SceneNode* OgreHead::getNode(){
	return mNode;
}

bool OgreHead::frameStarted(const Ogre::FrameEvent &evt)
{
	//mNode->yaw(Degree(evt.timeSinceLastFrame * 30));
	return true;
}

bool OgreHead::frameEnded(const Ogre::FrameEvent &evt)
{
	return true;
}