#include "monty.h"

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
	free_node();
	return (0);
}

/**
 * create_node - create a node
 * @n: Number of node
 *
 * Return: 1 for node success, otherwis NULL.
 */

stact_t *create_node(int n)
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

	if 9head == NULL)
		return;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * add_to-queue - Adds to a queue
 * @new_node: node pointer
 * @lin: opcode line number
 */

void add_to_queue(stack_t **new_code, __attribute__((unused))unsigned int lin)
{
	stack_t *tmp;

	if (new_code == NULL || *new_code == NULL)
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
