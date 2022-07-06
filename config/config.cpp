#include "config.h"

Config::Config() {
    PORT = 9006;
    TRIGMode = 0;
    LISTENTrigmode = 0;
    CONNTrigmode = 0;
    OPT_LINGER = 0;
    thread_num = 8;
}

void Config::parse_arg(int argc, char*argv[]) {
    int opt;
    const char *str = "p:m:o:t:";
    while ((opt = getopt(argc, argv, str)) != -1) {
        switch (opt) {
        case 'p': {
            PORT = atoi(optarg);
            break;
        }
        case 'm': {
            TRIGMode = atoi(optarg);
            break;
        }
        case 'o': {
            OPT_LINGER = atoi(optarg);
            break;
        }
        case 't': {
            thread_num = atoi(optarg);
            break;
        }
        default:
            break;
        }
    }
}