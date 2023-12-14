#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_numb: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_numb)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_numb);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_numb);
	printf("%c\n", ascii);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer pointing to top node of the stack.
 * @ln: Interger line number of opcode.
 */

void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer pointing to top node of the stack.
 * @ln: Interger line number of opcode.
 */

void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
