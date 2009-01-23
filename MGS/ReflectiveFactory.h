#ifndef _REFLECTIVE_FACTORY_H_
#define _REFLECTIVE_FACTORY_H_

#include <map>
#include <string>

class ReflectiveFactory
{
private:
	ReflectiveFactory();
	std::map<std::string,void*(*)()> constructors;

public:	
	static ReflectiveFactory& getInstance();
	void* create(const char* name);
	bool registerClass(const char* name, void*(*constructor)());
};

namespace
{
	template<class T>
	void* constructor()
	{
		return new T();
	}
}

#define REGISTER_CLASS(className) static bool className## _entry = ReflectiveFactory::getInstance().registerClass( #className , constructor< className >) 
#endif