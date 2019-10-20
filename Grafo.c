#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
int* MakeArrayNodes(Graph* graph){
  int* ArrayNodes=malloc(sizeof(int)*graph->V);
  for (int i = 0; i < graph->V; i++) {
    ArrayNodes[i]=graph->array[i].nodem;
  }
  return ArrayNodes;
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
    Graph* graph = createGraph(nodos);
    for (int i = 0; i < nodos; i++) {
          fgets(Line,150,fp);
          int size=0;
          int* NodeArray=SeparatedNodes(Line,&size);
          graph->array[i].nodem=NodeArray[0];
          AddNodes(graph,NodeArray,size);
          free(NodeArray);
    }
    int pathcount=0;
    int* ArrayNodes=MakeArrayNodes(graph);
    for (int i = 0; i < graph->V; i++) {
      for (int i2 = 1; i2 < graph->V; i2++) {
        if (i2!=i) {
          if (ContarCaminos(graph,ArrayNodes[i],ArrayNodes[i2],pathcount)==1) {
            printf("Caminos posibles entre: %d y %d son: %d\n",ArrayNodes[i],ArrayNodes[i2],ContarCaminos(graph,ArrayNodes[i],ArrayNodes[i2],pathcount));
          }
        }
      }
    }
    free(ArrayNodes);
    DeleteNodes(graph);
    free(graph->array);
    free(graph);
    }
    fclose(fp);
    return 0;
}
