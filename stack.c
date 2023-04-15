#include <stdlib.h>
#include <stdio.h>

typedef struct Stack
{
	int *items;
	int top;
	int size;
} stack_t;

stack_t *createEmptyStack(int size)
{
	stack_t *stack;

	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
		return (NULL);
	stack->items = malloc(sizeof(int) * size);
	if (stack->items == NULL)
		return (NULL);
	stack->top = -1; /* Set TOP pointer to -1 for empty stack */
	stack->size = size;

	return (stack);
}

stack_t *push(stack_t *stack, int item)
{
	int size;

	/* Get stack size */
	size = stack->size;

	if (stack->top == size - 1)
		printf("Cannot push item to full stack!\n");
	else
	{
		stack->top++;
		stack->items[stack->top] = item;
	}

	return (stack);
}

stack_t *pop(stack_t *stack)
{
	if (stack->top == -1)
		printf("Cannot pop item from empty stack\n");
	else
	{
		stack->top--;
	}

	return (stack);
}

int peek(stack_t *stack)
{
	if (stack->top == -1)
	{
		printf("The stack is currently empty, cannot peek.\n");
		exit(98);
	}

	return (stack->items[stack->top]);
}

int isEmpty(stack_t *stack)
{
	if (stack->top == -1)
		return (1);
	return (0);
}

int isFull(stack_t *stack)
{
	int size;

	size = stack->size;

	if (stack->top == size - 1)
		return (1);
	return (0);
}

stack_t *freeStack(stack_t *stack)
{
	free(stack->items);
	free(stack);
	stack = NULL;

	return (stack);
}

int main(void)
{
	int i;
	stack_t *stack;

	stack = createEmptyStack(10);

	push(stack, 10);
	push(stack, 7);
	push(stack, 3);
	push(stack, 9);
	push(stack, 12);
	push(stack, 3);
	push(stack, 5);
	push(stack, 8);
	push(stack, 1);
	push(stack, 4);
	push(stack, 6);

	printf("After pushing:");
	for (i = 0; i <= stack->top; i++)
		printf(" %d\n", stack->items[i]);
	return (0);
}
