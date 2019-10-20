#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_
typedef struct{
    int dest;
    struct AdjListNode* next;
}AdjListNode;
typedef struct{
    int nodem;
    struct AdjListNode *head;
}AdjList;
typedef struct{
    int V;
    AdjList* array;
}Graph;
int* SeparatedNodes(char* Line, int* size);
AdjListNode* newAdjListNode(int dest);
Graph* createGraph(int V);
void addEdge( Graph* graph, int src, int dest);
void DeleteNodes( Graph* graph);
void printGraph( Graph* graph);
int ContarCaminos(Graph* graph,int inicio, int destino,int pathcount);
void ContarCaminosAuxiliar(Graph* graph, int inicio, int destino,int* visited,int* pathcount);
void AddNodes(Graph* graph, int* NodeArray, int size) ;
#endif
