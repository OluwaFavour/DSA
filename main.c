#include "main.h"
#include <stdio.h>

int main(void)
{
	int numOfNodes, datas, i;
	DCList *head, *temp;

	head = NULL;
	printf("Enter the number of nodes to add: ");
	scanf("%d", &numOfNodes);

	for (i = 0; i < numOfNodes; i++)
	{
		printf("Enter the element for the node %d: ", i);
		scanf("%d", &datas);
		head = addDCNode(head, datas);
		if (head == NULL)
		{
			printf("Error creating list");
			exit(98);
		}
	}

	temp = head;
	printf("%d", temp->n);
	while ((temp = temp->next) != head)
	{
		printf(" %d", temp->n);
	}

	return (0);
}
