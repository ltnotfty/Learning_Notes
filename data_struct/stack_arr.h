#ifndef STACK_ARR

#define STACK_ARR


#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct  stack_arr_node_ {
	int val;
	struct stack_arr_node_ *next;
} stack_arr_node ;


typedef stack_arr_ {
    size_t capacity;
    size_t size;
    stack_arr_node *stack;
} stack_arr ;




stack_arr* init_stack_a();
void destroy_stack_a(stack_arr *st);

void push_stack_a(stack_arr *st, int val);
void pop_stack_a( stack_arr *st);

int top_stack_a( stack_arr *st);

bool is_empty_stack_a( stack_arr *st);
bool is_full_stack_a( stack_arr *st);


void expand_sz_stack_a( stack_arr *st, int times );



#endif
