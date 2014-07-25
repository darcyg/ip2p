#ifndef _PPSESSION_H_
#define _PPSESSION_H_

#include "talk/base/sigslot.h"
#include "talk/base/thread.h"
#include "talk/base/logging.h"
#include "talk/p2p/base/session.h"
#include "ppmessage.h"

using namespace cricket;

class PPSession : public BaseSession {
public:
    PPSession(const std::string& sid, 
              talk_base::Thread* signal_thread,
              talk_base::Thread* worker_thread,
              PortAllocator* port_allocator);
    ~PPSession();

    sigslot::signal1<PPSession*> SignalRequestSignaling;
    sigslot::signal2<PPSession* , const PPMessage&> SignalOutgoingMessage;
    sigslot::signal2<PPSession*, const std::string&> SignalReceivedTerminateReason;
    sigslot::signal2<PPSession*, const std::string&> SignalChannelGone;
    sigslot::signal2<PPSession*, const std::string&> SignalInfoMessage;
    sigslot::signal2<PPSession*, const PPMessage&> SignalErrorMessage;
    sigslot::signal1<PPSession*> SignalStateChanged;
    sigslot::signal1<PPSession*> SignalTimeout;

    virtual void OnMessage(talk_base::Message *pmsg);
    void OnSignalingReady() { BaseSession::OnSignalingReady(); }
    void OnIncomingMessage(const PPMessage& msg);
    
    bool Initiate(const std::string& content);
    bool Accept();
    bool Reject(const std::string& reason);
    bool Terminate() {
        return TerminateWithReason(STR_TERMINATE_SUCCESS);
    }
    bool TerminateWithReason(const std::string& reason);

    // fast access
    std::string content_name() {
        return content_name_ ;
    }

private:
    // some inernal help functions
    bool CheckState(State state);
    bool CreateTransportProxies(const P2PInfo& p2pInfo);
    bool OnRemoteCandidates(const P2PInfo& p2pInfo);
    bool SendTransportInfoMessage(const TransportProxy* transproxy, const Candidates& candidates);
    bool SendAllUnsentTransportInfoMessages();
    void onStateChanged(BaseSession*, BaseSession::State newState);

    // transport callback
    virtual void OnTransportRequestSignaling(Transport* transport);
    virtual void OnTransportConnecting(Transport* transport);
    virtual void OnTransportWritable(Transport* transport);
    virtual void OnTransportCandidatesReady(Transport* transport,
            const Candidates& candidates);
    virtual void OnTransportChannelGone(Transport* transport,
            const std::string& name);

    // Handlers for the various types of messages.  These functions may take
    // pointers to the whole stanza or to just the session element.
    bool OnInitiateMessage(const PPMessage& msg);
    bool OnAcceptMessage(const PPMessage& msg);
    bool OnRejectMessage(const PPMessage& msg);
    bool OnInfoMessage(const PPMessage& msg);
    bool OnTerminateMessage(const PPMessage& msg);
    bool OnTransportInfoMessage(const PPMessage& msg);

    std::string content_name_;    
    bool pending_candidates_;
};

#endif
