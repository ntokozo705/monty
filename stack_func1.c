#include "monty.h"

/**
 * add_2_stack - adds a node to stack
 * @new_node: pointer to new node
 * @ln: line number opcde
 */

void add_2_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: line number of the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	(void) line_numb;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a top node of the stack.
 * @line_numb: Interger the line number of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_numb)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_numb);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a top node of the stack.
 * @line_numb: Interger the line number of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_numb)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_numb);
	printf("%d\n", (*stack)->n);
}
