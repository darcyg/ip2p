#ifdef RELAYCLIENT_H_
#define RELAYCLIENT_H_


#include "talk/base/thread.h"



class RelayClient : public sigslot::has_slots<> {
 public:
	RelayClient(talk_base::Thread* client_thread);
	void Create();
	void Connect(talk::SocketAddress& relay_server_addr);
	sigslot::signal1<const std::string&> SignalPrint;
	
 private:
	 talk_base::Thread* thread_;
	 talk_base::SocketSever* socket_server_;
	 talk_base::AsynUdpSocket* asyn_udp_socket_;
}
#endif // RELAYCLIENT_H_
