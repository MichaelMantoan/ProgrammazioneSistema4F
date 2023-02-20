#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("errore numero argomenti");
    }
    execl("/usr/bin/cp","cp",argv[1],argv[2],(char*)0);
    printf("cp terminata con errori");
    return -1;

}