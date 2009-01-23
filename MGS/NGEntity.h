#ifndef _INTERFACE_H_
#define _INTERFACE_H_

class NGEntity
{
public:
	virtual void printName()=0;
	virtual void setRoot(Ogre::Root *mR, Ogre::SceneManager *mS)=0;
};

#endif