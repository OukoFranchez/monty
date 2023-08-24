#include "monty.h"

void monty_push(stack_t **stack_ptr, unsigned int line_no);
void monty_pall(stack_t **stack_ptr, unsigned int line_no);
void monty_pint(stack_t **stack_ptr, unsigned int line_no);
void monty_pop(stack_t **stack_ptr, unsigned int line_no);
void monty_swap(stack_t **stack_ptr, unsigned int line_no);

/**
 * monty_push - Pushes value to stack_t linked list.
 * @stack_ptr: pointer to top node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_push(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *temporary, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_no));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;

		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			set_op_tok_error(no_int_error(line_no));
			return;
		}
	}

	new->n = atoi(op_toks[1]);

	/* STACK mode of inserting at the front */
	if (check_mode(*stack_ptr) == STACK)
	{
		temporary = (*stack_ptr)->next;
		new->prev = *stack_ptr;
		new->next = temporary;

		if (temporary)
			temporary->prev = new;
		(*stack_ptr)->next = new;
	}
	/* QUEUE mode of inserting at tend */
	else
	{
		temporary = *stack_ptr;
		while (temporary->next)
			temporary = temporary->next;
		new->prev = temporary;
		new->next = NULL;
		temporary->next = new;
	}
}

/**
 * monty_pall - Prints values of stack_t linked list.
 * @stack_ptr: pointer to top mode node of stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file.
 */
void monty_pall(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *temporary = (*stack_ptr)->next;

	while (temporary)
	{
		printf("%d\n", temporary->n);
		temporary = temporary->next;
	}
	(void)line_no;
}

/**
 * monty_pint - Prints top value of stack_t linked list.
 * @stack_ptr: pointer to top mode node of a stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file
 */
void monty_pint(stack_t **stack_ptr, unsigned int line_no)
{
	if ((*stack_ptr)->next == NULL)
	{
		set_op_tok_error(pint_error(line_no));
		return;
	}

	printf("%d\n", (*stack_ptr)->next->n);
}


/**
 * monty_pop - Removes top value element of stack_t linked list.
 * @stack_ptr: pointer to top mode node of a stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file
 */
void monty_pop(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *next = NULL;

	if ((*stack_ptr)->next == NULL)
	{
		set_op_tok_error(pop_error(line_no));
		return;
	}

	next = (*stack_ptr)->next->next;
	free((*stack_ptr)->next);
	if (next)
		next->prev = *stack_ptr;
	(*stack_ptr)->next = next;
}

/**
 * monty_swap - Swaps top two value elements of stack_t linked list.
 * @stack_ptr: pointer to top mode node of a stack_t linked list.
 * @line_no: current working line no. of Monty bytecodes file
 */
void monty_swap(stack_t **stack_ptr, unsigned int line_no)
{
	stack_t *temporary;

	if ((*stack_ptr)->next == NULL || (*stack_ptr)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_no, "swap"));
		return;
	}

	temporary = (*stack_ptr)->next->next;
	(*stack_ptr)->next->next = temporary->next;
	(*stack_ptr)->next->prev = temporary;
	if (temporary->next)
		temporary->next->prev = (*stack_ptr)->next;
	temporary->next = (*stack_ptr)->next;
	temporary->prev = *stack_ptr;
	(*stack_ptr)->next = temporary;
}
