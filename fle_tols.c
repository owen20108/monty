#include "monty.h"

/**
 * opn_fle - open file
 * @file_name:  file path
 * Return: void
 */

void opn_fle(char *file_name)
{
	FILE *fdr = fopen(file_name, "r");

	if (file_name == NULL || fdr == NULL)
		errorz(2, file_name);

	reader_fle(fdr);
	fclose(fdr);
}


/**
 * reader_fle - read a file
 * @fdr: pointer for file
 * Return: void
 */

void reader_fle(FILE *fdr)
{
	int line_num, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fdr) != -1; line_num++)
	{
		format = analyz_line(buffer, line_num, format);
	}
	free(buffer);
}


/**
 * analyz_line - Separate every line into tokens to decide
 * which function to call
 * @buffer: line from file
 * @line_num: line number
 * @format:  storage format. 0 Nodes will be enter as a stack.
 * if 1 nodes will be enter as a queue.
 * Return: Return 0 if the opcode is stack, 1 if queue.
 */

int analyz_line(char *buffer, int line_num, int format)
{
	char *opcode, *val;
	const char *delimtr = "\n ";

	if (buffer == NULL)
		errorz(4);

	opcode = strtok(buffer, delimtr);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delimtr);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	finder_func(opcode, val, line_num, format);
	return (format);
}

/**
 * finder_func - find the  function for opcode
 * @opcode: opcode
 * @value:  opcode argument
 * @format:  storage format. 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will entered as a queue.
 * Return: void
 */
void finder_func(char *opcode, char *value, int ln, int format)
{
	int itr;
	int flags;

	instruction_t func_list[] = {
		{"push", push_to_stack},
		{"pall", printr_stack},
		{"pint", prnt_top},
		{"pop", pop_fun},
		{"nop", nothng},
		{"swap", swap_nodes},
		{"add", insrt_nodes},
		{"sub", two_nodz},
		{"div", divd_nodz},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", printr_chr},
		{"pstr", printr_strng},
		{"rotl", sub_tb},
		{"rotr", sub_bt},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flags = 1, itr = 0; func_list[itr].opcode != NULL; itr++)
	{
		if (strcmp(opcode, func_list[itr].opcode) == 0)
		{
			caller_func(func_list[itr].f, opcode, value, ln, format);
			flags = 0;
		}
	}
	if (flags == 1)
		errorz(3, ln, opcode);
}


/**
 * caller_func - Call the request function.
 * @func: Pointer for function
 * @op: string behalf the opcode.
 * @val: string behalf a numeric val
 * @ln: line numeber
 * @format: Formater specifier.0 Nodes will be enter as a stack.
 * if 1 nodes will be entered as a queue.
 */
void caller_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flags;
	int i;

	flags = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flags = -1;
		}
		if (val == NULL)
			errorz(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				errorz(5, ln);
		}
		node = create_node(atoi(val) * flags);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
