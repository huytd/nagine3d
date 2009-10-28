#include "StdAfx.h"
#include "Scripting.h"

void Scripting::redirectVMOutput()
{
	Ogre::LogManager::getSingletonPtr()->createLog("squirrel.log");
	sq_setprintfunc(SquirrelVM::GetVMPtr(), Scripting::printFunc);
}

void Scripting::printFunc(HSQUIRRELVM v,const SQChar * s,...)
{
     std::string tempStr = "";

     static SQChar temp[2048];
     va_list vl;
     va_start(vl,s);
     scvsprintf( temp,s,vl);
     va_end(vl);

     Ogre::LogManager::getSingletonPtr()->getLog("squirrel.log")->logMessage(temp);
}