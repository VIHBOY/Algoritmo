#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lista.h"
#define MAXSTRLEN 208
#define MAXWORD 3
int main(int argc, char const *argv[]) {
  char Name[100]="";
  char Line[100]="";
  if (argc>1) {
    printf("%s\n",argv[1]);
    strcpy(Name,argv[1]);
  }
  FILE* fp;
  fp=fopen(Name,"r");
  if (fp==NULL) {
    printf("No hay\n");
    return 0;
  }
  while (fgets(Line,150, fp)) {
        printf("Line: %s",Line);
    }
  fclose(fp);
  return 0;
}
