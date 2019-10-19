#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
void AddNodes(Graph* graph, int* NodeArray, int size) {
  int i=1;
  for (i = 1; i < size; i++) {
    printf("  Nodo: %d se conectara con: %d\n", NodeArray[0],NodeArray[i]);
    addEdge(graph,NodeArray[0],NodeArray[i]);
  }
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
          AddNodes(graph,NodeArray,size);
          free(NodeArray);
    }
    printGraph(graph);
    DeleteNodes(graph);
    free(graph->array);
    free(graph);
    }
    fclose(fp);
    return 0;
}
