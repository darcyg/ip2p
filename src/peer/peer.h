#ifndef _PEER_H_
#define _PEER_H_

#include <string>
#include <vector>

#include "talk/base/thread.h"
#include "talk/base/messagequeue.h"
#include "talk/base/socketaddress.h"

namespace talk_base{
  class AsyncSocket;
};

class Peer : public sigslot::has_slots<>, public talk_base::MessageHandler {  
 public:
  Peer(const talk_base::SocketAddress& server_addr, const std::string &id, talk_base::Thread *worker_thread);
  ~Peer(); 
  
  virtual void OnMessage(talk_base::Message *msg);
  void Start();
  int SendMessage(const std::string &, const std::vector<std::string>& );
  sigslot::signal1<bool> SignalOnline;
  sigslot::signal0<> SignalOffline;
  sigslot::signal1<const std::string &> SignalRemoteOnline;
  sigslot::signal1<const std::string &> SignalRemoteLogin;
  sigslot::signal1<const std::string &> SignalRemoteOffline;
  sigslot::signal2<const std::string &, const std::vector<std::string>& > SignalRemoteMessage;

  sigslot::signal1<const std::string &> SignalPrintString;    
 protected: 
  void onStart_w();
  void onConnectEvent(talk_base::AsyncSocket* socket);
  void onCloseEvent(talk_base::AsyncSocket* socket, int err);
  void onReadEvent(talk_base::AsyncSocket* socket);
  void processXML();

 private:
  enum {
      MSG_START,
  };
  std::string id_;
  talk_base::Thread*  worker_thread_;
  talk_base::AsyncSocket* sock_;
  
  bool isOnline_;
  std::string server_address_;
  unsigned short server_port_;
  
  std::vector<char> xmlBuffer;
};
    
#endif
