 #include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: argument counter
 * @argv: list of argument
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	opn_fle(argv[1]);
	free_nodez();
	return (0);
}

/**
 * create_node - Create  node.
 * @n: Number to go in the node.
 * Return: Upon sucess a pointer for node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		errorz(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodez - Frees nodes in the stack.
 */
void free_nodez(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}


/**
 * add_to_queue - Add  node  queue.
 * @new_node: Pointer for new node.
 * @ln: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
