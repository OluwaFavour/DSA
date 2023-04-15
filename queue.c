#include <stdio.h>
#include <stdlib.h>

void enqueue(int item);
void dequeue();

int *queue, size, front = -1, rear = -1;

int main(void)
{
	int i, opt, item;
	int flag;

	printf("Enter the size of your queue: ");
	scanf("%d", &size);

	queue = malloc(sizeof(int) * size);

	printf("Do you want to enqueue(1) or dequeue(2)? ");
	scanf("%d", &opt);

	if (opt == 1)
	{
		for (i = 0; i < size; i++)
		{
			printf("Enter the number to enqueue: ");
			scanf("%d", &item);
			enqueue(item);
		}
	}
	else if (opt == 2)
	{
		dequeue();
		printf("It's been dequeued\n");
	}

	for (i = 0; i < size; i++)
		printf("%d ", queue[i]);

	printf("\nDo you want to dequeue '3' or '4'? ");
	scanf("%d", &flag);
	if (flag == 3)
		return (0);
	else if (flag == 4)
	{
		while (flag != 0)
		{
			dequeue();
			printf("Press (q) to stop dequeue process, any key to continue!\n");
			scanf("%c", &flag);
		}
		printf("Exit... Returned 0\n");
	}

	return (0);
}

void enqueue(int item)
{
	if (rear == size - 1)
	{
		printf("The queue is already full!\n");
		exit(98);
	}
	else
	{
		if (front == -1)
			front = 0;
		rear++;
		queue[rear] = item;
	}
}

void dequeue()
{
	if (front == -1)
	{
		printf("Queue is empty\n");
		exit(99);
	}
	else
	{
		front++;
		if (front > rear)
			front = rear = -1;
	}
}
