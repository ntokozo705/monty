#include "monty.h"
stack_t *head = NULL;
/**
 * main - main function
 * @argc: argumenets counter
 * @argv: vector arguments
 *
 * Return: 0 always.
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: Monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - create a node
 * @n: Number of node
 *
 * Return: 1 for node success, otherwis NULL.
 */

stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;

	return (node);
}

/**
 * free_nodes - free nodes in stacks
 */

void free_nodes(void)
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
 * add_2_queue - Adds to a queue
 * @new_node: node pointer
 * @ln: opcode line number
 */

void add_2_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;
}
