#include <cstdio>
//#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>
#include <execution>

// typical use : sudo ./a.out /dev/input/event*
int main(int argc, char *argv[]) {
    struct input_event ev[64];
    int fd[argc], idev, value, size = sizeof(struct input_event);
    char name[256] = "Unknown", uniq[256] = "Unknown", phys[256] = "Unknown";

    if (argc == 1) return -1;

    int ndev = 1;
    while (ndev < argc && (fd[ndev] = open(argv[ndev], O_RDONLY | O_NONBLOCK)) != -1) {
        ndev++;
    }
    fprintf(stderr, "Found %i devices.\n", ndev);
    if (ndev == 1) return -1;

    for (idev = 1; idev < argc; idev++) {
        ioctl(fd[idev], EVIOCGNAME (sizeof(name)), name);
        ioctl(fd[idev], EVIOCGPHYS (sizeof(phys)), phys);
        ioctl(fd[idev], EVIOCGUNIQ (sizeof(uniq)), uniq);
        printf("'%s'; '%s'; '%s'; '%s'\n", argv[idev], name, uniq, phys);
    }

    for(ndev = 1; ndev < argc; ndev++) {
        close(fd[ndev]);
    }

    return 0;
}