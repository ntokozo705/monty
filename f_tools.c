#include "monty.h"
#include <stdio.h>

/**
 * open_file - opens a file
 * @file_name: file namepath
 *
 * Return: void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads file
 * @fd: pointer to file descriptor
 *
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_numb, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_numb = 1; getline(&buffer, &len, fd) != -1; line_numb++)
	{
		format = parse_line(buffer, line_numb, format);
	}
	free(buffer);
}
/**
 * parse_line - separates each line
 * @buffer: line from a file
 * @line_numb: number line
 * @format: storage format
 *
 * Return: returns 0 if stacke op, 1 if queue.
 */

int parse_line(char *buffer, int line_numb, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_the_func(opcode, value, line_numb, format);
	return (format);
}

/**
 * find_the_func - find the appropriate function for opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format
 * @ln: line number, 0 node stack
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void find_the_func(char *opcode, char *value, int ln, int format)
{
	int k;
	int flag;

	instruction_t func_list[] = {
		{"push", add_2_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, k = 0; func_list[k].opcode != NULL; k++)
	{
		if (strcmp(opcode, func_list[k].opcode) == 0)
		{
			call_func(func_list[k].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * call_func - Calls required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing opcode.
 * @val: string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */

void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int j;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_2_queue(&node, ln);
	}
	else
		func(&head, ln);
}
