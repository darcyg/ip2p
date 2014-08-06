#ifndef RELAYCLIENT_H_
#define RELAYCLIENT_H_

#include <stddef.h>
#include <string>

#include "talk/base/thread.h"
#include "talk/base/socketaddress.h"

namespace talk_base {
class SocketServer;
class AsyncUDPSocket;
class AsyncPacketSocket;
}

class RelayClient : public sigslot::has_slots<> {
 public:
	RelayClient(talk_base::Thread* client_thread);
	~RelayClient();
	void Create(talk_base::SocketAddress& loacal_addr);
	void Connect(talk_base::SocketAddress& relay_server_addr);
	int Send(const char* buf, size_t size);
	void OnReceive(
		talk_base::AsyncPacketSocket* socket, 
		const char* bytes, 
		size_t size,
    const talk_base::SocketAddress& remote_addr);
	sigslot::signal1<const std::string&> SignalPrint;
	
 private:
	talk_base::Thread* thread_;
	talk_base::SocketServer* socket_server_;
	talk_base::AsyncUDPSocket* asyn_udp_socket_;
	talk_base::SocketAddress* server_addr_;
};
#endif // RELAYCLIENT_H_
