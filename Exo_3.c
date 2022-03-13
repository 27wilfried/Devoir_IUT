/*
3- Reprendre la question 2 de manière à ce que le père envoie
 un nombre secret au processus fils. (Vous pouvez utiliser les pipes)
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int fd[2], result; // on creer un tableau de deux entrer
    pid_t pid;
    /* demande de création du pipe au système*/
    result = pipe(fd); // creation du tunnel result
    if (result < 0)
    { /* Une erreur s'est produite lors de la création du pipe*/
        fprintf(stderr, "Erreur de création du pipe (%d)\n", errno);
        return 1;
    }

    pid = fork(); // création du processus fils
    if (pid < 0)
    { /* Une erreur s'est produite lors de la création du processus fils*/
        fprintf(stderr, "Erreur de création du fils(%d)\n", errno);
        return 1;
    }

    // on fait la lecture ici
    if (pid == 0)
    {                 /*Nous sommes dans le fils*/
        close(fd[1]); /* Le fils ferme l'extrémité d'écriture du pipe*/
        char buffer[BUFSIZ + 1];
        while (read(fd[0], buffer, BUFSIZ) != 0)
        { /* Le fils se met en attente de lecture des données du pipe*/
            printf("Merci père, j'ai reçus votre message %s \n", buffer);
        }
        exit(0);
    }
    else
    {
        close(fd[0]); /* Le père ferme l'extrémité de lecture du pipe*/
        char buffer[BUFSIZ];
        printf("Code secret :");
        scanf("%s", buffer);                  /* Le père lit une chaine de caractère saisie au clavier*/
        write(fd[1], buffer, strlen(buffer)); /* le père écrit la chaine de caractère dans le pipe */
    }
}