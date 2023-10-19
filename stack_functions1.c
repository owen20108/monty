#include "monty.h"


/**
 * push_to_stack - push node stack.
 * @new_node: Pointer for  new node.
 * @ln: Interger behalf  line number of opcode.
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmprry;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmprry = head;
	head = *new_node;
	head->next = tmprry;
	tmprry->prev = head;
}


/**
 * printr_stack - print  node of stack.
 * @stack: Pointer pointing  top node of the stack.
 * @line_number: line number  the opcode.
 */
void printr_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmprry;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmprry = *stack;
	while (tmprry != NULL)
	{
		printf("%d\n", tmprry->n);
		tmprry = tmprry->next;
	}
}

/**
 * pop_fun - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop_fun(stack_t **stack, unsigned int line_number)
{
	stack_t *tmprry;

	if (stack == NULL || *stack == NULL)
		more_erroz(7, line_number);

	tmprry = *stack;
	*stack = tmprry->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmprry);
}

/**
 * prnt_top - Print top  of  stack.
 * @stack: Pointerto top  of the stack.
 * @line_number: Interger behalf the line number of the opcode.
 */
void prnt_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_erroz(6, line_number);
	printf("%d\n", (*stack)->n);
}
