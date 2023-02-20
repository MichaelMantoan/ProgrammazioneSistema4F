#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("errore numero argomenti");
    }
    execl("/usr/bin/cat","cat",argv[1],NULL);
    printf("exec terminata con errori");
    return -1;

}