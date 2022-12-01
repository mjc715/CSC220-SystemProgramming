#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>

#define FOUR_WEEKS 2419200
//-----------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    struct stat Stats;
    time_t CurrentTime = time(NULL);
    if (argc != 2) {
        printf("Too many/not enough args\n");
        exit(EXIT_FAILURE);
    }
    if (stat(argv[1], &Stats) == -1) {
        printf("Couldn't access file stats\n");
    }
    if (CurrentTime - Stats.st_mtime >= FOUR_WEEKS) {
        mode_t Mode = Stats.st_mode & 07777;
        Mode &= ~(0000222);
        // Mode &= ~(0000020);
        // Mode &= ~(0000002);
        chmod(argv[1], Mode);
    }
    return 0;
}
//-----------------------------------------------------------------------------
