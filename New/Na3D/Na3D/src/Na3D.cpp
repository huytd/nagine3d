// Na3D.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Na3D.h"

// This is an example of an exported variable
NA3D_API int nNa3D=0;

// This is an example of an exported function.
NA3D_API int fnNa3D(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see Na3D.h for the class definition
CNa3D::CNa3D()
{
	return;
}
