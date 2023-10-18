#include "monty.h"
#include "lists.h"

/**
 * rotl_handler - handles the rotl instruct
 * @stack: double pointer for stack
 * @line_number: number of line in the file
 */
void rotl_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = *stack;
	int numb  = 0;

	(void)line_number;

	if (*stack == NULL)
		return;
	tempo = get_dnodeint_at_index(*stack, 0);
	numb = tempo->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, numb);
}

/**
 * rotr_handler - handle the rotr instruct
 * @stack: double pointer
 * @line_number: number of lines
 */
void rotr_handler(stack_t **stack, unsigned int line_number)
{
	stack_t *tempo = *stack;
	int numb = 0, len = dlistint_len(*stack);

	(void)line_number;

	if (*stack == NULL)
		return;
	tempo = get_dnodeint_at_index(*stack, len - 1);
	numb = tempo->n;
	delete_dnodeint_at_index(stack, len - 1);
	add_dnodeint(stack, numb);
}

/**
 * stack_handler - handle stack instruct
 * @stack: double pointer for the stack
 * @line_number: number of the line in the file
 */
void stack_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 0;
}


/**
 * queue_handler - handles the queue instruct
 * @stack: double pointer for stack to push to
 * @line_number: number of the line in the file
 */
void queue_handler(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	data.qflag = 1;
}
