#include "monty.h"

/**
 * mul - multiplied the first two data
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->prev != NULL)
		temp = temp->next;
	temp_data = (temp->prev->n) * (temp->n);
	temp->prev->n = temp_data;
/*	(*stack) = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
*/
	pop(stack, 0);
}
/**
 * divide - multiplied the first two data
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Return: void
 */
void divide(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	div_t output;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->next != NULL)
		temp = temp->next;
	if ((temp->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	output = div((temp->prev->n), (temp->n));
	temp_data = output.quot;
	temp->prev->n = temp_data;
/*	(*stack) = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);*/
	pop (stack, 0);
}
/**
 * mod - finds the modulo or reminder of the first two data
 * @stack: pointer to the head
 * @line_number: line number in file.
 * Description: Finds the modulo or reminder of two
 *		element on the stack
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int temp_data;
	stack_t *temp;

	if (count_stacks(stack) < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack);
	while (temp->next != NULL)
		temp = temp->next;
	temp_data = (temp->n) % (temp->prev->n);
	temp->prev->n = temp_data;
/*	(*stack) = temp->next;
	if (temp->next != NULL)
	{
		temp->next->prev = NULL;
	}
	free(temp);*/
	pop(stack, 0);
}
