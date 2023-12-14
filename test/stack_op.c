#include "monty.h"

/**
 * mul_nodes - adds top element to stack
 * @stack: Pointer to top node
 * @line_num: line number of opcode
 */
void mul-nodes(stack_t **stack, unsigned int line_num)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_num, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod_nodes - adds top element of stack
 * @stack: pointer to top node
 * @line_numb: line number of opcode
 */
void mod_nodes(stack **stack, unsigned int line_numb)
{
	int Tsum;

	if (stack == NULL || *stack == NULL (*stack)->next == NULL)
		more_err(8, line_numb, "mod");

	if ((*stack)->n == 0)
		more_err(9, line_numb);
	(*stack) = (*stack)->next;
	Tsum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = Tsum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
