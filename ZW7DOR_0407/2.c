#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int child;

    mkfifo("Palko Patrik", S_IRUSR | S-IWUSR);
    child = fork();

    if(child > 0) {
        char s[1024];
        int fd;

        fd = open("Palko Patrik", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);
        close(fd);
        unlink("Palko Patrik");

    } else if(child == 0) {
        int fd = open("Palko Patrik", O_RDONLY);
        write(fd, "PP ZW7DOr\n", 12);
        close(fd);

    }
    return 0;
}
