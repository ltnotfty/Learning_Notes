#ifndef HEAP_ARR

#define HEAP_ARR

#include <stdbool.h>
#include <stdio.h>



typedef struct heap_arr_node_ {
    int val;    
} heap_arr_node;

typedef struct heap_arr_ {
    size_t size;
    size_t capacity;
    heap_arr_node *heap; 
} heap_arr ;

heap_arr * init_heap_a();
void destroy_heap_a( heap_arr *hp);

void push_heap_a( heap_arr *hp, int val );
void pop_heap_a( heap_arr *hp);

void adjust_heap_a( heap_arr *hp, size_t idx);                                                                                       

bool is_empty_heap_a( heap_arr *hp);

#endif
