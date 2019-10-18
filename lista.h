#ifndef _LISTA_H_INCLUDED_
#define _LISTA_H_INCLUDED_

struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};
struct AdjList{
    struct AdjListNode *head;
};
struct Graph{
    int V;
    struct AdjList* array;
};
struct AdjListNode* newAdjListNode(int dest);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph, int src, int dest);
void DeleteNodes(struct Graph* graph);
void printGraph(struct Graph* graph);
#endif
