#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero argomenti errato\n");
        exit(1);
    }

    int p1p2[2], pid;
    char str[50];

    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        do
        {
            printf("Inserisci una stringa: \n");
            scanf("%s", str);
            strcat(str, "\n");
            write(p1p2[1], str, strlen(str));
        } while (strcmp(str, "esci\n") != 0);

        printf("Esecuzione terminata\n");
        close(p1p2[1]);
        exit(0);
    }
    close(p1p2[1]);

    pid = fork();
    if (pid == 0)
    {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        close(1);
        open(argv[1], O_WRONLY | O_CREAT, 0677);

        execl("/usr/bin/sort", "sort", NULL);
        printf("errore nella sort");
        exit(1);
    }

    close(p1p2[0]);

    wait(&pid);

    return 0;
}
