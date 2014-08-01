#include <iostream>

#include "talk/base/helpers.h"
#include "talk/base/host.h"
#include "talk/base/logging.h"
#include "talk/base/physicalsocketserver.h"
#include "talk/base/socketaddress.h"

#include "console.h"

using namespace talk_base;

RelayClient::RelayClient(Thread* client_thread) {
	thread_ = client_thread;
	socket_server_ = thread_->socketserver();
	
}


void RelayClient::Create() {
	
}

void RelayClient::Connect(SocketAddress& relay_server_addr) {
	asyn_udp_socket_ = AsyncUDPSocket::Create(socket_server_, relay_server_addr);
	
}