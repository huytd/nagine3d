// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NA3D_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NA3D_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include "precomp.h"
// This class is exported from the Na3D.dll
class NA3D_API CNa3D {
public:
	CNa3D(void);
	// TODO: add your methods here.
};

extern NA3D_API int nNa3D;

NA3D_API int fnNa3D(void);
