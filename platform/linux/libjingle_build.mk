LIB_SRCS += \
	deps/libjingle/talk/base/asyncfile.cc\
	deps/libjingle/talk/base/asynchttprequest.cc\
	deps/libjingle/talk/base/asyncsocket.cc\
	deps/libjingle/talk/base/asynctcpsocket.cc\
	deps/libjingle/talk/base/asyncudpsocket.cc\
	deps/libjingle/talk/base/autodetectproxy.cc\
	deps/libjingle/talk/base/bandwidthsmoother.cc\
	deps/libjingle/talk/base/base64.cc\
	deps/libjingle/talk/base/basicpacketsocketfactory.cc\
	deps/libjingle/talk/base/bytebuffer.cc\
	deps/libjingle/talk/base/checks.cc\
	deps/libjingle/talk/base/common.cc\
	deps/libjingle/talk/base/cpuid.cc\
	deps/libjingle/talk/base/cpumonitor.cc\
	deps/libjingle/talk/base/diskcache.cc\
	deps/libjingle/talk/base/event.cc\
	deps/libjingle/talk/base/filelock.cc\
	deps/libjingle/talk/base/fileutils.cc\
	deps/libjingle/talk/base/firewallsocketserver.cc\
	deps/libjingle/talk/base/flags.cc\
	deps/libjingle/talk/base/helpers.cc\
	deps/libjingle/talk/base/host.cc\
	deps/libjingle/talk/base/httpbase.cc\
	deps/libjingle/talk/base/httpclient.cc\
	deps/libjingle/talk/base/httpcommon.cc\
	deps/libjingle/talk/base/httprequest.cc\
	deps/libjingle/talk/base/httpserver.cc\
	deps/libjingle/talk/base/ipaddress.cc\
	deps/libjingle/talk/base/logging.cc\
	deps/libjingle/talk/base/md5c.cc\
	deps/libjingle/talk/base/messagehandler.cc\
	deps/libjingle/talk/base/messagequeue.cc\
	deps/libjingle/talk/base/multipart.cc\
	deps/libjingle/talk/base/natserver.cc\
	deps/libjingle/talk/base/natsocketfactory.cc\
	deps/libjingle/talk/base/nattypes.cc\
	deps/libjingle/talk/base/nethelpers.cc\
	deps/libjingle/talk/base/network.cc\
	deps/libjingle/talk/base/openssladapter.cc\
	deps/libjingle/talk/base/optionsfile.cc\
	deps/libjingle/talk/base/pathutils.cc\
	deps/libjingle/talk/base/physicalsocketserver.cc\
	deps/libjingle/talk/base/proxydetect.cc\
	deps/libjingle/talk/base/proxyinfo.cc\
	deps/libjingle/talk/base/proxyserver.cc\
	deps/libjingle/talk/base/ratetracker.cc\
	deps/libjingle/talk/base/sharedexclusivelock.cc\
	deps/libjingle/talk/base/signalthread.cc\
	deps/libjingle/talk/base/socketadapters.cc\
	deps/libjingle/talk/base/socketaddress.cc\
	deps/libjingle/talk/base/socketaddresspair.cc\
	deps/libjingle/talk/base/socketpool.cc\
	deps/libjingle/talk/base/socketstream.cc\
	deps/libjingle/talk/base/ssladapter.cc\
	deps/libjingle/talk/base/sslsocketfactory.cc\
	deps/libjingle/talk/base/stream.cc\
	deps/libjingle/talk/base/stringdigest.cc\
	deps/libjingle/talk/base/stringencode.cc\
	deps/libjingle/talk/base/stringutils.cc\
	deps/libjingle/talk/base/systeminfo.cc\
	deps/libjingle/talk/base/task.cc\
	deps/libjingle/talk/base/taskparent.cc\
	deps/libjingle/talk/base/taskrunner.cc\
	deps/libjingle/talk/base/testclient.cc\
	deps/libjingle/talk/base/thread.cc\
	deps/libjingle/talk/base/timeutils.cc\
	deps/libjingle/talk/base/timing.cc\
	deps/libjingle/talk/base/transformadapter.cc\
	deps/libjingle/talk/base/urlencode.cc\
	deps/libjingle/talk/base/versionparsing.cc\
	deps/libjingle/talk/base/virtualsocketserver.cc\
	deps/libjingle/talk/base/worker.cc\
	deps/libjingle/talk/p2p/base/constants.cc\
	deps/libjingle/talk/p2p/base/p2ptransport.cc\
	deps/libjingle/talk/p2p/base/p2ptransportchannel.cc\
	deps/libjingle/talk/p2p/base/parsing.cc\
	deps/libjingle/talk/p2p/base/port.cc\
	deps/libjingle/talk/p2p/base/portallocator.cc\
	deps/libjingle/talk/p2p/base/portallocatorsessionproxy.cc\
	deps/libjingle/talk/p2p/base/portproxy.cc\
	deps/libjingle/talk/p2p/base/pseudotcp.cc\
	deps/libjingle/talk/p2p/base/relayport.cc\
	deps/libjingle/talk/p2p/base/relayserver.cc\
	deps/libjingle/talk/p2p/base/relayserver_main.cc\
	deps/libjingle/talk/p2p/base/rawtransport.cc\
	deps/libjingle/talk/p2p/base/rawtransportchannel.cc\
	deps/libjingle/talk/p2p/base/session.cc\
	deps/libjingle/talk/p2p/base/sessiondescription.cc\
	deps/libjingle/talk/p2p/base/sessionmanager.cc\
	deps/libjingle/talk/p2p/base/sessionmessages.cc\
	deps/libjingle/talk/p2p/base/stun.cc\
	deps/libjingle/talk/p2p/base/stunport.cc\
	deps/libjingle/talk/p2p/base/stunrequest.cc\
	deps/libjingle/talk/p2p/base/stunserver.cc\
	deps/libjingle/talk/p2p/base/stunserver_main.cc\
	deps/libjingle/talk/p2p/base/tcpport.cc\
	deps/libjingle/talk/p2p/base/transport.cc\
	deps/libjingle/talk/p2p/base/transportchannel.cc\
	deps/libjingle/talk/p2p/base/transportchannelproxy.cc\
	deps/libjingle/talk/p2p/base/udpport.cc\
	deps/libjingle/talk/p2p/client/basicportallocator.cc\
	deps/libjingle/talk/p2p/client/connectivitychecker.cc\
	deps/libjingle/talk/p2p/client/httpportallocator.cc\
	deps/libjingle/talk/p2p/client/socketmonitor.cc\
	deps/libjingle/talk/session/tunnel/pseudotcpchannel.cc\
	deps/libjingle/talk/session/tunnel/tunnelsessionclient.cc\
	deps/libjingle/talk/session/tunnel/securetunnelsessionclient.cc\
	deps/libjingle/talk/xmllite/qname.cc\
	deps/libjingle/talk/xmllite/xmlbuilder.cc\
	deps/libjingle/talk/xmllite/xmlconstants.cc\
	deps/libjingle/talk/xmllite/xmlelement.cc\
	deps/libjingle/talk/xmllite/xmlnsstack.cc\
	deps/libjingle/talk/xmllite/xmlparser.cc\
	deps/libjingle/talk/xmllite/xmlprinter.cc\
	deps/libjingle/talk/xmpp/constants.cc\
	deps/libjingle/talk/xmpp/hangoutpubsubclient.cc\
	deps/libjingle/talk/xmpp/iqtask.cc\
	deps/libjingle/talk/xmpp/jid.cc\
	deps/libjingle/talk/xmpp/moduleimpl.cc\
	deps/libjingle/talk/xmpp/mucroomconfigtask.cc\
	deps/libjingle/talk/xmpp/mucroomhistorytask.cc\
	deps/libjingle/talk/xmpp/mucroomlookuptask.cc\
	deps/libjingle/talk/xmpp/pubsubclient.cc\
	deps/libjingle/talk/xmpp/pubsub_task.cc\
	deps/libjingle/talk/xmpp/pubsubtasks.cc\
	deps/libjingle/talk/xmpp/receivetask.cc\
	deps/libjingle/talk/xmpp/saslmechanism.cc\
	deps/libjingle/talk/xmpp/xmppclient.cc\
	deps/libjingle/talk/xmpp/xmppengineimpl.cc\
	deps/libjingle/talk/xmpp/xmppengineimpl_iq.cc\
	deps/libjingle/talk/xmpp/xmpplogintask.cc\
	deps/libjingle/talk/xmpp/xmppstanzaparser.cc\
	deps/libjingle/talk/xmpp/xmpptask.cc\
	deps/libjingle/talk/base/latebindingsymboltable.cc\
	deps/libjingle/talk/base/linux.cc\
	deps/libjingle/talk/base/linuxfdwalk.cc\
	deps/libjingle/talk/base/libdbusglibsymboltable.cc\
	deps/libjingle/talk/base/unixfilesystem.cc\
	deps/libjingle/talk/base/opensslidentity.cc\
	deps/libjingle/talk/base/opensslstreamadapter.cc\
	deps/libjingle/talk/base/posix.cc\
	deps/libjingle/talk/base/sslidentity.cc\
	deps/libjingle/talk/base/sslstreamadapter.cc\
	deps/libjingle/talk/examples/login/jingleinfotask.cc\
	deps/libjingle/talk/examples/login/xmppauth.cc\
	deps/libjingle/talk/examples/login/xmpppump.cc\
	deps/libjingle/talk/examples/login/xmppsocket.cc\
