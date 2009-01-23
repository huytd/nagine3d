#include "ReflectiveFactory.h"

ReflectiveFactory& ReflectiveFactory::getInstance()
{
	static ReflectiveFactory instance;
	return instance;
}

void* ReflectiveFactory::create(const char* name)
{
	std::map<std::string,void*(*)()>::iterator i=constructors.find(std::string(name));
	if(i==constructors.end())
		return NULL;
	else
		return (*(i->second))();
}

bool ReflectiveFactory::registerClass(const char* name, void*(*constructor)())
{
	constructors[std::string(name)]=constructor;
	return true;
}

ReflectiveFactory::ReflectiveFactory()
{
}