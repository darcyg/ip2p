#include <iostream>
#include <time.h>

#include "talk/base/basicdefs.h"
#include "talk/base/common.h"
#include "talk/base/helpers.h"
#include "talk/base/logging.h"
#include "talk/base/thread.h"
#include "talk/base/messagequeue.h"

#include "console.h"
#include "prober.h"
#include "peer.h"

int main(int argc, char *argv[]) {
    //talk_base::LogMessage::LogToDebug(talk_base::LS_VERBOSE);
    talk_base::LogMessage::LogToDebug(talk_base::LS_ERROR);
    talk_base::LogMessage::LogTimestamps();
    talk_base::LogMessage::LogThreads();

    if ( argc < 5) {
        std::cout << "usage: neble session_server relay_server local_name  remote_name  [logfile, default is pplog.txt]" << std::endl;
				return 0;
    }
    
    IceProber *pProber ;
    if ( argc == 6)  {
        pProber = new IceProber(argv[5]);
    } else {
        pProber = new IceProber();
    }

    SimpleConsole myConsole;
    pProber->SignalPrintString.connect( &myConsole, &SimpleConsole::OnPrintString);
    pProber->SignalExit.connect( &myConsole, &SimpleConsole::OnExit);

    pProber->Login(argv[1], argv[2], 1979, argv[3], argv[4]);
    pProber->Run();    
    
    return 0;
}

