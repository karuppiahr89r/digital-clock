#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main() {
    time_t rawtime;
    struct tm *timeinfo;

    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);

        // Clear screen
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        printf("====== DIGITAL CLOCK ======\n");
        printf("Time: %02d : %02d : %02d\n",
               timeinfo->tm_hour,
               timeinfo->tm_min,
               timeinfo->tm_sec);
        printf("===========================\n");

        // Delay of 1 second
        #ifdef _WIN32
            Sleep(1000);
        #else
            sleep(1);
        #endif
    }

    return 0;
}
