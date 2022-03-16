#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <md5.h>

int main(int argc, char *argv[])
  { 
    /*int n;
    printf("Entrer le nombre de fichier en MD5 : ");
    scanf("%d",&n);*/
    if(argc>1000){
      printf("Entrer pas plus de fichiers dans les argurments");
      exit(1);
    }
    if(argc>0){
    int i;
    i=0;
    for(i=1;i<argc;i++){    
    char buffer[100];
    unsigned char *MD5;
    MD5=MD5File(argv[i], buffer);
    printf("%s",argv[i]);
    printf(" %s\n",MD5);
    if(argv[i]=NULL)
         break;
      } 
    }
    return 0;
  }
