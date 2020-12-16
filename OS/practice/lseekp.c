#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[]) {

    int source, dest, n;
    char buf;
    int filesize;
    int i;

    if (argc != 3) {
        fprintf(stderr, "usage %s <source> <dest>", argv[0]);
        exit(-1);
    }

    if ((source = open(argv[1], 0400)) < 0) { //read permission for user on source
        fprintf(stderr, "can't open source");
        exit(-1);
    }

    if ((dest = creat(argv[2], 0700)) < 0) { //rwx permission for user on dest
        fprintf(stderr, "can't create dest");
        exit(-1);
    }

    filesize = lseek(source, (off_t) 0, SEEK_END); //filesize is lastby +offset
    printf("Source file size is %d\n", filesize);

    for (i = 0; i <=filesize/2; i++) { //read byte by byte from end
        int j=i*2;
        lseek(source, (off_t) j, SEEK_SET);

        n = read(source, &buf, 1);

        if (n != 1) {
            fprintf(stderr, "can't read 1 byte");
            exit(-1);
        }

        n = write(dest, &buf, 1);
        if (n != 1) {
            fprintf(stderr, "can't write 1 byte");
            exit(-1);
        }

    }
    write(STDOUT_FILENO, "DONE\n", 5);
    close(source);
    close(dest);



    return 0;
}