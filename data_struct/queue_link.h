#ifndef QUEUE_LINK

#define QUEUE_LINK



typedef struct queue_link_node_ {
    int val;
    struct queue_link_node_ *next;
} queue_link_node ;


typedef queue_link_ {
   queue_link_node *front;
   queue_link_node *back;
   size_t size;
} queue_link;


queue_link * init_queue_l();
void  destroy_queue_l( queue_link *q);

void push_queue_l( queue_link *q, int val);
void pop_queue_l( queue_link *q);

int front_queue_l( queue_link *q);
int back_queue_l( queue_link *q);


bool is_empty_queue_l( queue_link *q);




#endif
