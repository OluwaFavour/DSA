#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>

typedef struct NodeStruct
{
	int n;
	struct NodeStruct *prev;
	struct NodeStruct *next;
} Node;
Node *addNode(Node *head, int data);

typedef struct NodesStruct
{
	int o;
	struct NodesStruct *next;
} Nodes;
Nodes *addNodes(Nodes *head, int datas);

typedef struct SingleCircularStruct
{
	int n;
	struct SingleCircularStruct *next;
} SCList;
SCList *addSCircularNode(SCList *head, int data);

typedef struct DoubleCircularStruct
{
	int n;
	struct DoubleCircularStruct *prev;
	struct DoubleCircularStruct *next;
} DCList;
DCList *addDCNode(DCList *head, int data);
#endif
