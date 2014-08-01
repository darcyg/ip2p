


class SimpleConsole : public sigslot::has_slots<> {
public:
    SimpleConsole() {
    }
    ~SimpleConsole() {
    }
    
    void OnPrintString(const std::string& msg) {
        time_t tim = time(NULL);
        struct tm * now = localtime(&tim);
        char *time_string = asctime(now);
        if (time_string) {
            size_t time_len = strlen(time_string);
            if (time_len > 0) {
            time_string[time_len-1] = 0;    // trim off terminating \n
            }
        }

        std::cout << time_string << " " << msg << std::endl;
    }

    void OnExit(const int ret) {
        exit(-1);
    }
}; 