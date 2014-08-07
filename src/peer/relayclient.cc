#include "relayclient.h"

#include <iostream>

#include "talk/base/helpers.h"
#include "talk/base/host.h"
#include "talk/base/logging.h"
#include "talk/base/physicalsocketserver.h"
#include "talk/base/asyncudpsocket.h"
#include "talk/base/asyncpacketsocket.h"

#include "console.h"

using namespace std;
using namespace talk_base;



RelayClient::RelayClient(talk_base::Thread* client_thread) {
	thread_ = client_thread;
	socket_server_ = thread_->socketserver();
	
}

RelayClient::~RelayClient() {
	if (server_addr_) 
		delete server_addr_;
	
}
void RelayClient::Create(SocketAddress& loacal_addr) {
	asyn_udp_socket_ = AsyncUDPSocket::Create(socket_server_, loacal_addr);
}

void RelayClient::Connect(talk_base::SocketAddress& relay_server_addr) {
	asyn_udp_socket_->SignalReadPacket.connect(this, &RelayClient::OnReceive);
	server_addr_ = new SocketAddress(relay_server_addr);
}

int RelayClient::Send(const char* buf, size_t size) {
	return asyn_udp_socket_->SendTo(buf, size, *server_addr_);
}

void RelayClient::OnReceive(
		talk_base::AsyncPacketSocket* socket, 
		const char* bytes, 
		size_t size,
    const talk_base::SocketAddress& remote_addr) {
	cout << "receive " << size <<" bytes data!"<< endl;	
	
}
int main(int argc, char *argv[]) {
	
	SocketAddress my_addr("127.0.0.1", 7000 + (rand() % 1000));
	SocketAddress server_addr("112.124.37.110", 5000);
	
	if (argv[1]) {
		server_addr.FromString(argv[1]);
	}
	Thread* main_thread = Thread::Current();
	const char* buffer = "this is relay client!";
	RelayClient relay_client(main_thread);
	
	relay_client.Create(my_addr);
	relay_client.Connect(server_addr);
	relay_client.Send(buffer, sizeof(buffer));
	main_thread->Run();
	return 0;
}