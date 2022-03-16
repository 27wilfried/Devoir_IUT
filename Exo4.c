#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <md5.h>

int main(int argc, char *argv[])
  {
    if(argc<2){
      printf("Entrer au moins un fichier dans les argurments");
      exit(1);
    }      
    char buffer[100];
    unsigned char *MD5;
    MD5= MD5File(argv[1], buffer);
    printf("%s ",MD5);  
    return 0;
  }
