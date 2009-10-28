// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include <Ogre.h>
#include <OIS/OIS.h>
#include <CEGUI/CEGUI.h>
#include <OgreCEGUIRenderer.h>

#include "na3de\include\GameManager.h"
#include "SplashScreen.h"

#ifdef _DEBUG
#pragma comment (lib, "na3de/lib/debug/na3d.lib")
#else
#pragma comment (lib, "na3de/lib/release/na3d.lib")
#endif


int main(int argc, char **argv)

{
	GameManager* game = new GameManager();
	
	try
	{
		// initialize the game and switch to the first state
		game->start(SplashScreen::getInstance());
	}
	catch (Ogre::Exception& e)
	{
		#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32 
        MessageBox( NULL, e.what(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
		#else
				fprintf(stderr, "An exception has occurred: %s\n",
						e.what());
		#endif
	}

	delete game;
	
	return 0;
}