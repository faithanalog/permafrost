#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void handle_signal(int signal) {
    exit(0);
}

int main(int argc, char** argv) {
    if (argc > 1 && (strcmp("-h", argv[1]) == 0 || strcmp("--help", argv[1]) == 0)) {
        puts("permafrost - sleep until SIGINT/SIGTERM/SIGKILL is received and then exit.");
        exit(0);
    }
    
    struct sigaction exit_gracefully = {
        .sa_handler = handle_signal
    };
    sigaction(SIGINT, &exit_gracefully, NULL);
    sigaction(SIGTERM, &exit_gracefully, NULL);
    sigaction(SIGKILL, &exit_gracefully, NULL);  // This one will get ignored in many cases but that's life
    pause();
    return 0;
}
