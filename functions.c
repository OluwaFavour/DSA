#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
  * addNode - Creates a linked list by adding to the tail of the list
  *
  * @head: A pointer to the head node
  * @data: Data to be inserted into the node
  *
  * Return: Returns a pointer to the head node
  */
Node *addNode(Node *head, int data)
{
	Node *newNode, *temp;

	newNode = malloc(sizeof(Node));
	if (newNode == NULL)
		return (NULL);
	if (head == NULL)
	{
		newNode->n = data;
		newNode->next = NULL;
		newNode->prev = NULL;

		return (newNode);
	}

	/* If head is not null */
	newNode->n = data;
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
	newNode->prev = temp;
	newNode->next = NULL;
	temp = NULL;

	return (head);
}


Nodes *addNodes(Nodes *head, int datas)
{
	Nodes *newNodes, *temp;
	newNodes = malloc(sizeof(Nodes));
	if (head == NULL)
	{
		newNodes->o = datas;
		newNodes->next = NULL;

		return (newNodes);
	}
	
	newNodes->o = datas;
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNodes;
	newNodes->next = NULL;
	temp = NULL;

	return (head);
}

SCList *addSCircularNode(SCList *head, int data)
{
	SCList *newNode, *temp;

	newNode = malloc(sizeof(SCList));
	if (newNode == NULL)
		return (NULL);
	newNode->n = data;
	if (head == NULL)
	{
		newNode->next = NULL;
		return (newNode);
	}
	if (head->next == NULL)
	{
		newNode->next = head;
		head->next = newNode;

		return (head);
	}

	temp = head;
	while (temp->next != head)
		temp = temp->next;
	newNode->next = head;
	temp->next = newNode;
	temp = NULL;

	return (head);
}

DCList *addDCNode(DCList *head, int data)
{
	DCList *newNode, *temp;
	newNode = malloc(sizeof(DCList));
	if (newNode == NULL)
		return (NULL);
	newNode->n = data;
	if (head == NULL)
	{
		newNode->next = NULL;
		newNode->prev = NULL;
		return (newNode);
	}
	if (head->next == NULL)
	{
		newNode->next = head;
		newNode->prev = head;
		head->next = newNode;
		head->prev = newNode;

		return (head);
	}

	temp = head;
	while (temp->next != head)
		temp = temp->next;
	newNode->next = head;
	newNode->prev = temp;
	temp->next = newNode;
	temp = NULL;

	return (head);
}
