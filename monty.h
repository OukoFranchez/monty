#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

/* GLOBAL OPCODE TOKENS */
extern char **op_toks;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* PRIMARY INTERPRETER FUNCTIONS */
void freeStack(stack_t **stack);
int initStack(stack_t **stack);
int checkMode(stack_t *stack);
void freeTokens(void);
unsigned int token_arr_len(void);
int monty_run(FILE *script_fd);
void set_op_tok_error(int error_code);

/* OPCODE FUNCTIONS */
void push_monty(stack_t **stack_ptr, unsigned int line_no);
void pall_monty(stack_t **stack_ptr, unsigned int line_no);
void pint_monty(stack_t **stack_ptr, unsigned int line_no);
void pop_monty(stack_t **stack_ptr, unsigned int line_no);
void swap_monty(stack_t **stack_ptr, unsigned int line_no);
void add_monty(stack_t **stack_ptr, unsigned int line_no);
void monty_nop(stack_t **stack_ptr, unsigned int line_no);
void sub_monty(stack_t **stack_ptr, unsigned int line_no);
void div_monty(stack_t **stack_ptr, unsigned int line_no);
void mul_monty(stack_t **stack_ptr, unsigned int line_no);
void mod_monty(stack_t **stack_ptr, unsigned int line_no);
void pchar_monty(stack_t **stack_ptr, unsigned int line_no);
void pstr_monty(stack_t **stack_ptr, unsigned int line_no);
void rotl_monty(stack_t **stack_ptr, unsigned int line_no);
void rotr_monty(stack_t **stack_ptr, unsigned int line_no);
void stack_monty(stack_t **stack_ptr, unsigned int line_no);
void queue_monty(stack_t **stack_ptr, unsigned int line_no);

/* CUSTOM STANDARD LIBRARY FUNCTIONS */
char **strtow(char *string, char *delim);
char *get_int(int n);

/* ERROR MESSAGES & ERROR CODES */
int usageError(void);
int mallocError(void);
int f_open_error(char *filename);
int unknown_op_error(char *opcode, unsigned int line_number);
int no_int_error(unsigned int line_number);
int popError(unsigned int line_number);
int pintError(unsigned int line_number);
int short_stack_error(unsigned int line_number, char *op);
int divError(unsigned int line_number);
int pcharError(unsigned int line_number, char *message);

/* INTEGER AND STRING MANIPULATION */
char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
						char *buff, int buff_size);

/* TOKENIZE STRINGS */
int is_char_delim(char ch, char *delim);
int get_word_length(char *string, char *delim);
int get_word_count(char *string, char *delim);
char *get_next_word(char *string, char *delim);

#endif /* __MONTY_H__ */
