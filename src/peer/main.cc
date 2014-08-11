#include <iostream>
#include <time.h>
#if POSIX
#include <unistd.h>
#else
#include <getopt.h>
#endif

#include "talk/base/basicdefs.h"
#include "talk/base/common.h"
#include "talk/base/helpers.h"
#include "talk/base/logging.h"
#include "talk/base/thread.h"
#include "talk/base/messagequeue.h"

#include "console.h"
#include "prober.h"
#include "peer.h"

using namespace std;


void usage() {
  std::cout << "usage: neble [options] [target]"<< std::endl;
  cout << "-m    my name ID." << endl;
  cout << "-n    remote name ID." << endl;
  cout << "-d    setup default config." << endl;
  cout << "-r    setup relay server address." << endl;
  cout << "-s    setup session server address." << endl;

}
int main(int argc, char *argv[]) {
  //talk_base::LogMessage::LogToDebug(talk_base::LS_VERBOSE);
  talk_base::LogMessage::LogToDebug(talk_base::LS_ERROR);
  talk_base::LogMessage::LogTimestamps();
  talk_base::LogMessage::LogThreads();
  int opt;
  extern char *optarg;
  char* session_server = "112.124.37.110:1979", *relay_server = "112.124.37.110:5000", *my_name = "melo", *remote_name = "chale";
  while(1) {
    opt = getopt(argc, argv, "m:n:s:r:");
    if(opt < 0)
    break;
    switch(opt) {
      case 'm': {
        my_name = optarg;
        break;
      }
      case 'n': {
        remote_name = optarg;
        break;
      }
      case 'r': {
        relay_server = optarg;
        break;
      }
      case 's': {
        session_server = optarg;
        break;
      }
      default:
        usage();
        return 0;
    }
  }
  IceProber *pProber = new IceProber();
  SimpleConsole myConsole;
  pProber->SignalPrintString.connect( &myConsole, &SimpleConsole::OnPrintString);
  pProber->SignalExit.connect( &myConsole, &SimpleConsole::OnExit);

  pProber->Login(session_server, relay_server, my_name, remote_name);
  pProber->Run();    
  
  return 0;
}

