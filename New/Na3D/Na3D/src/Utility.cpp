// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "stdafx.h"

#include "Utility.h"

Overlay* Utility::overlay;
OverlayManager* Utility::overlayManager;
OverlayContainer* Utility::panel;

Utility::Utility()
{
}

void Utility::InitText()
{
	if (!overlayManager) overlayManager = OverlayManager::getSingletonPtr();
	
	overlayManager->destroyAllOverlayElements();

	try
	{
	panel = static_cast<OverlayContainer*>(
	overlayManager->createOverlayElement("Panel", "PanelName"));
	panel->setMetricsMode(Ogre::GMM_PIXELS);
	panel->setPosition(10, 10);
	panel->setDimensions(100, 100);
	}catch (Ogre::Exception& e)
	{
	}
	if(!overlay)
	overlay = overlayManager->create("OverlayName");
	
	overlay->clear();
	overlay->add2D(panel);
	overlay->show();
}

//Grabbed from Ogre3D Wiki
void Utility::drawText(Ogre::String tText, int tSize, Ogre::Vector2 tPosition, Ogre::ColourValue tTopColor, Ogre::ColourValue tBotColor)
{
	// Create a text area
	TextAreaOverlayElement* textArea = static_cast<TextAreaOverlayElement*>(
		overlayManager->createOverlayElement( "TextArea", tText));
		//"TextAreaName" + StringConverter::toString(Ogre::Timer::Timer().getMicrosecondsCPU()) ) );
	textArea->setMetricsMode(Ogre::GMM_PIXELS);
	textArea->setPosition(tPosition.x, tPosition.y);
	textArea->setDimensions(100, 100);
	textArea->setCaption(tText);
	textArea->setCharHeight(tSize);
	textArea->setFontName("StarWars");
	/*textArea->setColourBottom(ColourValue(0.3, 0.5, 0.3));
	textArea->setColourTop(ColourValue(0.5, 0.7, 0.5));*/
	textArea->setColourBottom(tBotColor);
	textArea->setColourTop(tTopColor);
	// Add the text area to the panel
	
	panel->addChild(textArea);
}
//======================================================================================
		
//======================================================================================

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
	rect->setCorners(x1, y1, x2, y2);
	rect->setMaterial(imgName);

	rect->setRenderQueueGroup(RENDER_QUEUE_BACKGROUND);
	rect->setBoundingBox(AxisAlignedBox(-100000.0*Vector3::UNIT_SCALE, 100000.0*Vector3::UNIT_SCALE));
	SceneNode* node = mSceneMgr->getRootSceneNode()->createChildSceneNode(imgName);
	node->attachObject(rect);
}
