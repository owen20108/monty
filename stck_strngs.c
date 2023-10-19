#include "monty.h"

/**
 * printr_chr - Print the Ascii table.
 * @stack: Pointer for top node of  stack.
 * @line_num: Interger show line number of the opcode.
 */
void printr_chr(stack_t **stack, unsigned int line_num)
{
	int asci;

	if (stack == NULL || *stack == NULL)
		strng_erroz(11, line_num);

	asci = (*stack)->n;
	if (asci < 0 || asci > 127)
		strng_erroz(10, line_num);
	printf("%c\n", asci);
}

/**
 * printr_strng - Print string.
 * @stack: Pointer for top node of stack.
 * @lnum: Interger show line number of the opcode.
 */
void printr_strng(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	int asci;
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmpo = *stack;
	while (tmpo != NULL)
	{
		asci = tmpo->n;
		if (asci <= 0 || asci > 127)
			break;
		printf("%c", asci);
		tmpo = tmpo->next;
	}
	printf("\n");
}

/**
 * sub_tp - subtitute  first node of the stack to  bottom.
 * @stack: Pointer for  top node of the stack.
 * @lnum: Interger show  line number of the opcode.
 */
void sub_tb(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpo = *stack;
	while (tmpo->next != NULL)
		tmpo = tmpo->next;

	tmpo->next = *stack;
	(*stack)->prev = tmpo;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * sub_bt - subtitute the last node of the stack to the top.
 * @stack: Pointer for top node of the stack.
 * @lnum: Interger show the line number of of the opcode.
 */
void sub_bt(stack_t **stack, __attribute__((unused))unsigned int lnum)
{
	stack_t *tmpo;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpo = *stack;

	while (tmpo->next != NULL)
		tmpo = tmpo->next;

	tmpo->next = *stack;
	tmpo->prev->next = NULL;
	tmpo->prev = NULL;
	(*stack)->prev = tmpo;
	(*stack) = tmpo;
}
