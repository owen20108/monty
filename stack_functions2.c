#include "monty.h"

/**
 * nothng - Does nothing.
 * @stack: Pointer for top of stack.
 * @line_number: Interger behalf the line number of  opcode.
 */
void nothng(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodz - Swap top two elements stack.
 * @stack: Pointer for top node of stack.
 * @line_number: Interger behalf the line number of  opcode.
 */
void swap_nodz(stack_t **stack, unsigned int line_number)
{
	stack_t *tmprry;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_erroz(8, line_number, "swap");
	tmprry = (*stack)->next;
	(*stack)->next = tmprry->next;
	if (tmprry->next != NULL)
		tmprry->next->prev = *stack;
	tmprry->next = *stack;
	(*stack)->prev = tmprry;
	tmprry->prev = NULL;
	*stack = tmprry;
}

/**
 * insrt_nodes - Add top two elements of the stack.
 * @stack: Pointer for top node of stack.
 * @line_number: Interger behalf the line number of of the opcode.
 */
void insrt_nodes(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_erroz(8, line_number, "add");

	(*stack) = (*stack)->next;
	sums = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * two_nodz - Add top two elements stack.
 * @stack: Pointer for top node of stack.
 * @line_number: Interger behalf the line number of opcode.
 */
void two_nodz(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_erroz(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sums = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * divd_nodz - Add two elements of the stack.
 * @stack: Pointer for top of the stack.
 * @line_number: Interger behalf the line number of of the opcode.
 */
void divd_nodz(stack_t **stack, unsigned int line_number)
{
	int sums;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_erroz(8, line_number, "div");

	if ((*stack)->n == 0)
		more_erroz(9, line_number);
	(*stack) = (*stack)->next;
	sums = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sums;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
