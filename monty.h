#ifndef MONTY_H_
#define MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list behalf  stackor queue
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void opn_fle(char *file_name);
int analyz_line(char *buffer, int line_number, int format);
void reader_fle(FILE *);
int len_chars(FILE *);
void finder_func(char *, char *, int, int);

/*Stack operations*/
stack_t *create_node(int n);
void free_nodes(void);
void printr_stack(stack_t **, unsigned int);
void push_to_stack(stack_t **, unsigned int);
void add_to_queue(stack_t **, unsigned int);

void caller_func(op_func, char *, char *, int, int);

void prnt_top(stack_t **, unsigned int);
void pop_fun(stack_t **, unsigned int);
void nothng(stack_t **, unsigned int);
void swap_nodz(stack_t **, unsigned int);

/*Math operations*/
void insrt_nodes(stack_t **, unsigned int);
void two_nodz(stack_t **, unsigned int);
void divd_nodz(stack_t **, unsigned int);
void mult_nodz(stack_t **, unsigned int);
void mod_nodes(stack_t **, unsigned int);

/*String operations*/
void printr_chr(stack_t **, unsigned int);
void printr_strng(stack_t **, unsigned int);
void sub_tb(stack_t **, unsigned int);

/*Errorz h*/
void errorz(int error_code, ...);
void more_erroz(int error_code, ...);
void strng_erroz(int error_code, ...);
void sub_bt(stack_t **, unsigned int);

#endif
