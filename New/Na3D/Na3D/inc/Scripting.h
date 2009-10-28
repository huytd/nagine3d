// Copyright (C) 2009 Tran Duc Huy
// This file is part of the "Nagine3D Game Framework".

#include "precomp.h"
#include <Ogre.h>
#include "sqplus.h" // Include the SQPlus header
#include <stdarg.h> // needed for redirecting squirrel output

using namespace SqPlus;

class Scripting{
public:
	static void NA3D_API printFunc(HSQUIRRELVM v,const SQChar * s,...);
	static void NA3D_API redirectVMOutput();
};
