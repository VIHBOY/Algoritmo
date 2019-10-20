#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <stdlib.h>
#include <time.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#define LARGO_MAXIMO 256
#define MAXSTRLEN 208
#define MAXWORD 3
#include "lista.h"
int* SeparatedNodes(char* Line,int* size){
  int len=strlen(Line)/2;
  *size=len;
  int* NodeArray=malloc(sizeof(int)*len);
  char *p=strtok (Line," ");
  int i2=0;
  while (p != NULL){
    NodeArray[i2]=atoi(p);
    p = strtok (NULL," ");
    i2++;}
  return NodeArray;
}
AdjListNode* newAdjListNode(int dest){
    AdjListNode* newNode =(AdjListNode*) malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;}
Graph* createGraph(int V){
    Graph* graph =( Graph*) malloc(sizeof(Graph));
    graph->V=V;
    graph->array=(AdjList*)malloc(V*sizeof(AdjList));
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}
void addEdge(Graph* graph, int src, int dest){
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next=graph->array[src].head;
    graph->array[src].head = (struct AdjListNode*)newNode;
}
void DeleteNodes(Graph* graph){
    int v;
    for (v = 1; v < graph->V+1; ++v)
    {
        AdjListNode* pCrawl =(AdjListNode*) graph->array[v].head;
        while (pCrawl!=NULL)
        {
            AdjListNode* pCrawl2= pCrawl;
            pCrawl = (AdjListNode*)pCrawl->next;
            free(pCrawl2);
        }
        printf("\n");
    }
}
void printGraph(Graph* graph){
    int v;
    for (v = 1; v < graph->V+1; ++v)
    {
        AdjListNode* pCrawl = (AdjListNode*)graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = (AdjListNode*)pCrawl->next;
        }
        printf("\n");
    }
}
void AddNodes(Graph* graph, int* NodeArray, int size) {
  int i=1;
  for (i = 1; i < size; i++) {
    printf("  Nodo: %d se conectara con: %d\n", NodeArray[0],NodeArray[i]);
    addEdge(graph,NodeArray[0],NodeArray[i]);
  }
}
void ContarCaminosAuxiliar(Graph* graph, int inicio, int destino,int* visited,int* pathcount){
  visited[inicio]=1;
  printf("inicio:%d\n",inicio );
  if (inicio==destino) {
    printf("AcA\n" );
    *pathcount=*pathcount+1;
  }
  else{
    AdjListNode* pCrawl =(AdjListNode*) graph->array[inicio].head;
    while (pCrawl!=NULL)
    {
      if (!visited[pCrawl->dest]) {
          ContarCaminosAuxiliar(graph,pCrawl->dest,destino,visited,pathcount);
      }
      pCrawl = (AdjListNode*)pCrawl->next;
    }
  }
  visited[inicio]=0;
}
int ContarCaminos(Graph* graph,int inicio, int destino,int pathcount){
  int* visited=malloc(sizeof(int)*graph->V+1);
  for (int i = 0; i < graph->V+1; i++) {
    visited[i]=0;}
  ContarCaminosAuxiliar(graph,inicio,destino,visited,&pathcount);
  free(visited);
  return pathcount;
  }
