
#ifndef HEARTRATEMONITOR_HH
#define HEARTRATEMONITOR_HH

#include "HeartRateMonitorProtocol.hh"
#include "umlrtcapsule.hh"
#include "umlrtcapsuleclass.hh"
#include "umlrtinmessage.hh"
#include "umlrttimerid.hh"
#include "umlrttimerprotocol.hh"
struct UMLRTCommsPort;
struct UMLRTSlot;

class Capsule_HeartRateMonitor : public UMLRTCapsule
{
public:
    Capsule_HeartRateMonitor( const UMLRTCapsuleClass * cd, UMLRTSlot * st, const UMLRTCommsPort * * border, const UMLRTCommsPort * internal, bool isStat );
    enum BorderPortId
    {
        borderport_HeartRatePort
    };
protected:
    HeartRateMonitorProtocol_baserole HeartRatePort() const;
public:
    enum InternalPortId
    {
        internalport_timer
    };
protected:
    UMLRTTimerProtocol_baserole timer() const;
public:
    enum PartId
    {
    };
    enum PortId
    {
        port_HeartRatePort,
        port_timer
    };
    virtual void bindPort( bool isBorder, int portId, int index );
    virtual void unbindPort( bool isBorder, int portId, int index );
    UMLRTTimerId timerID;
    virtual void inject( const UMLRTInMessage & message );
    virtual void initialize( const UMLRTInMessage & message );
    const char * getCurrentStateString() const;
private:
    enum State
    {
        top__monitoring,
        top__idle,
        SPECIAL_INTERNAL_STATE_UNVISITED
    };
    const char * stateNames[2];
    State currentState;
    void entryaction_____top__onRegisterListener__ActionChain4__onEntry( const UMLRTInMessage & msg );
    void transitionaction_____top__init__ActionChain3__onInit( const UMLRTInMessage & msg );
    void transitionaction_____top__onRegisterListener__ActionChain4__TransitionAction9( const UMLRTInMessage & msg );
    void transitionaction_____top__onUnregisterListener__ActionChain5__TransitionAction10( const UMLRTInMessage & msg );
    void actionchain_____top__init__ActionChain3( const UMLRTInMessage & msg );
    void actionchain_____top__onRegisterListener__ActionChain4( const UMLRTInMessage & msg );
    void actionchain_____top__onUnregisterListener__ActionChain5( const UMLRTInMessage & msg );
    State state_____top__monitoring( const UMLRTInMessage & msg );
    State state_____top__idle( const UMLRTInMessage & msg );
};
extern const UMLRTCapsuleClass HeartRateMonitor;

#endif

