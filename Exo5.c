#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <md5.h>
int main(int argc, char *argv[])
{
  if(argc!=3){
    fprintf(stderr,"le format exiger est : %s <fichier_source><fichier_destination>\n",argv[0]);
    return 1;
  }
  FILE *fichier1, *fichier2;
  int retour;
  fichier1=fopen(argv[1],"r");
  if(fichier1==NULL){
    printf("Erreur d'ouverture %s\n",argv[1]);
    exit(1);
  }
  fichier2=fopen(argv[2],"w");
  if(fichier2==NULL){
    fclose(fichier1);
    printf("Erreur d'ouverture %s\n",argv[2]);
    exit(2);
  }
  else{
  char buffer[100];
    unsigned char *MD5_1, *MD5_2;
    MD5_1= MD5File(argv[1], buffer);
    printf("%s\n",MD5_1);
    int car_courant=0;
    while(1){
      car_courant=fgetc(fichier1);
      fputc(car_courant,fichier2);
      if (car_courant==EOF){
        break;
      }
    } 
  //fclose(fichier2);
  //fichier2=fopen(argv[2],"r");
  char buf[100];
    MD5_2= MD5File(argv[2], buf);
    printf("%s\n",MD5_2);
  }
  fclose(fichier1);
  fclose(fichier2);
  return 0;
}
