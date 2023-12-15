#include "monty.h"
/**
 * count_stacks - counts the number of elements in the stack
 * @stack: head pointer
 * Return: number of elements
 */
int count_stacks(stack_t **stack)
{
	stack_t *temp;
	int count;

	count = 1;
	if ((*stack) == NULL)
		return (0);
	temp = (*stack);
	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	printf("count is %d elements\n", count);
	return (count);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = temp;
}
/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->prev != NULL)
		temp = temp->prev;
	temp_data = (temp->n) + (temp->next->n);
	temp->next->n = temp_data;

	(*stack) = temp->next;
	
	if (temp->next != NULL)
		temp->next->prev = NULL;
	free(temp);
}
/**
 * nop - does virtually nothing
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
/**
 * nop - does virtually nothing
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
        int temp_data;
        stack_t *temp;

        if (count_stacks(stack) < 2)
        {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
        }
        temp = (*stack);
        while (temp->prev != NULL)
                temp = temp->prev;
        temp_data = (temp->n) - (temp->next->n);
        temp->next->n = temp_data;

        (*stack) = temp->next;

        if (temp->next != NULL)
                temp->next->prev = NULL;
        free(temp);
}
