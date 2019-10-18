#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
int* SeparatedNodes(char* Line){
  int len=strlen(Line)/2;
  int* NodeArray=malloc(sizeof(int)*len);
  char *p=strtok (Line," ");
  int i2=0;
  while (p != NULL){
    NodeArray[i2]=atoi(p);
    p = strtok (NULL," ");
    i2++;}
  return NodeArray;
}
void AddNodes(/* arguments */) {
  /* code */
}
int main(int argc, char const *argv[]){
  char Name[100]="";
  char Line[100]="";
  if (argc>1) {
    printf("%s\n",argv[1]);
    strcpy(Name,argv[1]);}
  FILE* fp;
  fp=fopen(Name,"r");
  if (fp==NULL) {
    printf("No hay\n");
    return 0;
  }
  while (fgets(Line,150,fp)) {
    int nodos=atoi(Line);
    printf("Nuevo Grafo de: %d Nodos\n",nodos );
    struct Graph* graph = createGraph(nodos);
    for (int i = 0; i < nodos; i++) {
          fgets(Line,150,fp);
          int* NodeArray=SeparatedNodes(Line);
          AddNodes(NodeArray,graph);
          free(NodeArray);
    }
    }
    fclose(fp);
    return 0;
}
