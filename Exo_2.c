/*
2- Ecrire un programme qui crée un processus fils.
Le fils affiche le pid de son père. Le père affiche le pid de son fils.
*/

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid < 0)
    {
        /* En cas d'erreur programme le s'arrete*/
        fprintf(stderr, "Erreur de création du processus (%d) (%d)\n", pid, errno);
        return 1;
    }
    if (pid == 0)
    {
        /* le processus fils*/
        printf("je suis le fils (%d), mon père est (%d)\n", getpid(), getppid());
    }
    else
    {
        /* le père*/
        int status;
        printf("Je suis le père (%d) mon fils que je viens de créer (%d)"
               "s'est terminé avec le code d'erreur (%d)",
               getpid(), pid, status);
    }
    printf("\n");
    return 0;
}