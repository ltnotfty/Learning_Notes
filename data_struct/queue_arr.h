#ifndef QUEUE_ARR

#define QUEUE_ARR



typedef struct queue_arr_node_ {
    int val;
    struct queue_arr_node_ *next;
} queue_arr_node;

typedef queue_arr_ {
    size_t front;
    size_t back;
    size_t capacity;
    queue_arr_node *queue;
} queue_arr ;


queue_arr * init_queue_a();
void destroy_queue_a( queue_arr *q);

void push_queue_a( queue_arr *q, int val);
void pop_queue_a( queue_arr *a);

int front_queue_a( queue_arr *q);
int back_queue_a( queue_arr *q );


bool is_empty_queue_a( queue_arr *q);
bool is_full_queue_a( queue_arr *q)



void expand_sz_queue_a( queue_arr *q, int times );




#endif
