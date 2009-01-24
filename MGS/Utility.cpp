#include "Utility.h"

Utility::Utility()
{
}
/*
void Utility::drawTxt(Ogre::String tName, Ogre::UTFString tText, Ogre::SceneNode *tNode, Ogre::Real tSize , Ogre::Real tHeight)
{
	MovableText* msg = new MovableText(tName, tText);
	msg->setFontName("MyFont");
	msg->setTextAlignment(MovableText::H_CENTER, MovableText::V_ABOVE);
	msg->setColor(Ogre::ColourValue::ColourValue(1,0,0,1));
	msg->showOnTop(true);
	msg->setAdditionalHeight( tHeight );
	msg->setCharacterHeight(tSize);
	tNode->attachObject(msg);

}*/

void Utility::tellScreenW(int sW)
{
	screenWidth = sW;
}

void Utility::tellScreenH(int sH)
{
	screenHeight = sH;
}

void Utility::drawIMG(Ogre::SceneManager *mSceneMgr, Ogre::String imgName, Ogre::String imgFileName, Ogre::Real x1, Ogre::Real y1, Ogre::Real x2, Ogre::Real y2)
{
	MaterialPtr material = MaterialManager::getSingleton().create(imgName, "General");
	material->getTechnique(0)->getPass(0)->createTextureUnitState(imgFileName);
	material->getTechnique(0)->getPass(0)->setDepthCheckEnabled(false);
	material->getTechnique(0)->getPass(0)->setDepthWriteEnabled(false);
	material->getTechnique(0)->getPass(0)->setLightingEnabled(false);

	Rectangle2D* rect = new Rectangle2D(true);

	//Corners vẽ 2D có dạng như sau
	/*
	+________1________+
	|		 :		  |
	|		0.5	      |
	|		 :	      |
   -1...-0.5..0..0.5...1
	|		 :	      |
	|		-0.5      |
	|		 :	      |
	+_______-1________+
	*/
	rect->setCorners(-0.5, 0.5, 0.5, -0.5);
	rect->setMaterial(imgName);

	rect->setRenderQueueGroup(RENDER_QUEUE_BACKGROUND);
	rect->setBoundingBox(AxisAlignedBox(-100000.0*Vector3::UNIT_SCALE, 100000.0*Vector3::UNIT_SCALE));
	SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode(imgName);
	node->attachObject(rect);
}

Ogre::UTFString Utility::ConvertToUTF(Ogre::String String)
{
   Ogre::UTFString UTFString;
   int i;
   Ogre::UTFString::code_point cp;
   for (i=0; i<(int)String.size(); ++i)
   {
      cp = String[i];
      cp &= 0xFF;
      UTFString.append(1, cp);
   }
   return UTFString;
} 
