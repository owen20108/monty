#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list behalf of a stack or queue
 * @n: integer
 * @prev: pointer for  previous element of the stack or queue
 * @next: pointer for  next element of the stack or queue
 *
 * Description: doubly linked list node struct
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{

	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode function
 * @opcode: opcode
 * @f: function for opcode
 *
 * Description: opcode function
 * stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
 * struct args_s - structure for arguments of main
 * @av: name of  file command line
 * @ac: number of arguments of main
 * @line_number: number  current line in the file
 *
 * Description: arguments throw to main from command line
 * use in different functions, organized in struct of clarity
 */
typedef struct args_s
{
	char *av;
	int ac;
	unsigned int line_number;
} args_t;

/**
 * struct data_s - extern data for access inside functions
 * @line: line of file
 * @words: parsed line
 * @stack: pointer for the stack
 * @fptr: file pointer
 * @qflag: flag for queue or stack
 */
typedef struct data_s
{
	char *line;
	char **words;
	stack_t *stack;
	FILE *fptr;
	int qflag;
} data_t;

typedef stack_t dlistint_t;

extern data_t data;

#define DATA_INIT {NULL, NULL, NULL, NULL, 0}

#define USAGE "USAGE: monty file\n"
#define FILE_ERROR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define SWAP_FAIL "L%u: can't swap, stack too short\n"
#define ADD_FAIL "L%u: can't add, stack too short\n"
#define SUB_FAIL "L%u: can't sub, stack too short\n"
#define DIV_FAIL "L%u: can't div, stack too short\n"
#define DIV_ZERO "L%u: division by zero\n"
#define MUL_FAIL "L%u: can't mul, stack too short\n"
#define MOD_FAIL "L%u: can't mod, stack too short\n"
#define PCHAR_FAIL "L%u: can't pchar, stack empty\n"
#define PCHAR_RANGE "L%u: can't pchar, value out of range\n"

void monty(args_t *args);

void (*get_func(char **parsed))(stack_t **, unsigned int);
void push_handler(stack_t **stack, unsigned int line_number);
void pall_handler(stack_t **stack, unsigned int line_number);

void pint_handler(stack_t **stack, unsigned int line_number);
void pop_handler(stack_t **stack, unsigned int line_number);
void swap_handler(stack_t **stack, unsigned int line_number);
void add_handler(stack_t **stack, unsigned int line_number);
void nop_handler(stack_t **stack, unsigned int line_number);

void sub_handler(stack_t **stack, unsigned int line_number);
void div_handler(stack_t **stack, unsigned int line_number);
void mul_handler(stack_t **stack, unsigned int line_number);
void mod_handler(stack_t **stack, unsigned int line_number);

void rotl_handler(stack_t **stack, unsigned int line_number);
void rotr_handler(stack_t **stack, unsigned int line_number);
void stack_handler(stack_t **stack, unsigned int line_number);
void queue_handler(stack_t **stack, unsigned int line_number);

void pchar_handler(stack_t **stack, unsigned int line_number);
void pstr_handler(stack_t **stack, unsigned int line_number);

int count_word(char *s);
char **strtow(char *str);
void free_everything(char **args);

void free_all(int all);


#endif /* MONTY_H */
