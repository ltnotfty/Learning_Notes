#ifndef STACK_LINK

#define STACK_LINK


typedef struct stack_link_node_ {
	stack_link_node_ *next;
	int val;
} stack_link_node;


typedef struct stack_link_ {
    size_t sz;
    stack_link_node * head;
    stack_link_node * tail;
} stack_link;



stack_link * init_stack_l();
void destroy_stack_l( stack_link* st);


int top_stack_l( stack_link* st);
void pop_stack_l( stack_link * st);
void push_stack_l( stack_link * st);

bool is_empty_stack_l( stack_link *st );



#endif
