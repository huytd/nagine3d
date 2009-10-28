#ifndef InputManager_H
#define InputManager_H

#include "precomp.h"
#include <Ogre.h>
#include <OIS/OIS.h>
/*
#include <OISMouse.h>
#include <OISKeyboard.h>
#include <OISJoyStick.h>
#include <OISInputManager.h>
*/


class InputManager : public OIS::KeyListener, OIS::MouseListener, OIS::JoyStickListener {
public:
    virtual ~InputManager( void );

    void NA3D_API initialise( Ogre::RenderWindow *renderWindow );
    void NA3D_API capture( void );

    void NA3D_API addKeyListener( OIS::KeyListener *keyListener, const std::string& instanceName );
    void NA3D_API addMouseListener( OIS::MouseListener *mouseListener, const std::string& instanceName );
    void NA3D_API addJoystickListener( OIS::JoyStickListener *joystickListener, const std::string& instanceName );

    void NA3D_API removeKeyListener( const std::string& instanceName );
    void NA3D_API removeMouseListener( const std::string& instanceName );
    void NA3D_API removeJoystickListener( const std::string& instanceName );

    void NA3D_API removeKeyListener( OIS::KeyListener *keyListener );
    void NA3D_API removeMouseListener( OIS::MouseListener *mouseListener );
    void NA3D_API removeJoystickListener( OIS::JoyStickListener *joystickListener );

    void NA3D_API removeAllListeners( void );
    void NA3D_API removeAllKeyListeners( void );
    void NA3D_API removeAllMouseListeners( void );
    void NA3D_API removeAllJoystickListeners( void );

    void NA3D_API setWindowExtents( int width, int height );

    OIS::Mouse*     getMouse( void );
    OIS::Keyboard*  getKeyboard( void );
    OIS::JoyStick*  getJoystick( unsigned int index );

    int getNumOfJoysticks( void );

    static InputManager* getSingletonPtr( void );
private:
    InputManager( void );
    InputManager( const InputManager& ) { }
    InputManager & operator = ( const InputManager& );

    bool keyPressed( const OIS::KeyEvent &e );
    bool keyReleased( const OIS::KeyEvent &e );

    bool mouseMoved( const OIS::MouseEvent &e );
    bool mousePressed( const OIS::MouseEvent &e, OIS::MouseButtonID id );
    bool mouseReleased( const OIS::MouseEvent &e, OIS::MouseButtonID id );

    bool povMoved( const OIS::JoyStickEvent &e, int pov );
    bool axisMoved( const OIS::JoyStickEvent &e, int axis );
    bool sliderMoved( const OIS::JoyStickEvent &e, int sliderID );
    bool buttonPressed( const OIS::JoyStickEvent &e, int button );
    bool buttonReleased( const OIS::JoyStickEvent &e, int button );

    OIS::InputManager *mInputSystem;
    OIS::Mouse        *mMouse;
    OIS::Keyboard     *mKeyboard;

    std::vector<OIS::JoyStick*> mJoysticks;
    std::vector<OIS::JoyStick*>::iterator itJoystick;
    std::vector<OIS::JoyStick*>::iterator itJoystickEnd;

    std::map<std::string, OIS::KeyListener*> mKeyListeners;
    std::map<std::string, OIS::MouseListener*> mMouseListeners;
    std::map<std::string, OIS::JoyStickListener*> mJoystickListeners;

    std::map<std::string, OIS::KeyListener*>::iterator itKeyListener;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListener;
    std::map<std::string, OIS::JoyStickListener*>::iterator itJoystickListener;

    std::map<std::string, OIS::KeyListener*>::iterator itKeyListenerEnd;
    std::map<std::string, OIS::MouseListener*>::iterator itMouseListenerEnd;
    std::map<std::string, OIS::JoyStickListener*>::iterator itJoystickListenerEnd;

    static InputManager *mInputManager;
};
#endif