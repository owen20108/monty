#include "monty.h"

/**
 * errorz - Print exact error message  by their error code
 * @error_code:  error codes are:
 * (1) => The user do not  file or more to program.
 * (2) => The file provide is not  file that can open or read.
 * (3) => The file provid has invalid instruction.
 * (4) => When program  unable to malloc memory.
 * (5) => When parameter passinstruction "push" is not int.
 * (6) => When stack empty for pint.
 * (7) => When the stack empty for pop.
 * (8) => When stack too short for operation.
 */
void errorz(int error_code, ...)
{
	va_list arg;
	char *opr;
	int ln_num;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			ln_num = va_arg(arg, int);
			opr = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln_num, opr);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_erroz - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void more_erroz(int error_code, ...)
{
	va_list arg;
	char *opr;
	int ln_num;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			ln_num = va_arg(arg, unsigned int);
			opr = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln_num, opr);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * strng_erroz - deal with errors.
 * @error_code: error codes:
 * (10) ~> number inside node outside ASCII bounds.
 * (11) ~> The stack empty.
 */
void strng_erroz(int error_code, ...)
{
	va_list arg;
	int ln_num;

	va_start(arg, error_code);
	ln_num = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
