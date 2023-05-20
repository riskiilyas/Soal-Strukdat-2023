
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/* Struktur Node */

typedef struct queueNode_t {
    int data;
    struct queueNode_t *next;
} QueueNode;

/* Struktur ADT Queue */

typedef struct queue_t {
    QueueNode   *_front, 
                *_rear;
    unsigned _size;
} Queue;

/* Function prototype */

void queue_init(Queue *queue);
bool queue_isEmpty(Queue *queue);
void queue_push(Queue *queue, int value);
void queue_pop(Queue *queue);
int  queue_front(Queue *queue);
int  queue_size(Queue *queue);

/* Function definition below */

void queue_init(Queue *queue)
{
    queue->_size = 0;
    queue->_front = NULL;
    queue->_rear = NULL;
}

bool queue_isEmpty(Queue *queue) {
    return (queue->_front == NULL && queue->_rear == NULL);
}

void queue_push(Queue *queue, int value)
{
    QueueNode *newNode = (QueueNode*) malloc(sizeof(QueueNode));
    if (newNode) {
        queue->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (queue_isEmpty(queue))                 
            queue->_front = queue->_rear = newNode;
        else {
            queue->_rear->next = newNode;
            queue->_rear = newNode;
        }
    }
}

void queue_pop(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        QueueNode *temp = queue->_front;
        queue->_front = queue->_front->next;
        free(temp);
        
        if (queue->_front == NULL)
            queue->_rear = NULL;
        queue->_size--;
    }
}

int queue_front(Queue *queue)
{
    if (!queue_isEmpty(queue)) {
        return (queue->_front->data);
    }
    return (int)0;
}

int queue_size(Queue *queue) {
    return queue->_size;
}

int main(int argc, char const *argv[])
{
    // Buat objek QueueArray
    Queue leftSide, rightSide, outSide;

    // PENTING! Jangan lupa diinisialisasi
    queue_init(&leftSide);
    queue_init(&rightSide);
    queue_init(&outSide);

    for (int i = 0; i < 6; i++){
        int a;
        scanf("%d", &a);
        queue_push(&leftSide, a);

        if(queue_size(&leftSide)>4) {
            queue_push(&rightSide, queue_front(&leftSide));
            queue_pop(&leftSide);
        }
    }
    
    int command=0;
    while(command!=-1) {
        scanf("%d", &command);
        if (command==0){
            queue_push(&rightSide, queue_front(&leftSide));
            queue_push(&leftSide, queue_front(&rightSide));
            queue_pop(&leftSide);
            queue_pop(&rightSide);
        } else if(command== 1) {
            int inp;
            scanf("%d", &inp);
            queue_push(&leftSide, inp);
            queue_push(&outSide, queue_front(&leftSide));
            queue_pop(&leftSide);
        }
    }

    if(queue_isEmpty(&outSide)) {
        printf("No Cars left the Roundabout");
    } else {
        printf("Cars left the Roundabout: ");
    }

    while(!queue_isEmpty(&outSide)) {
        printf("%d ", queue_front(&outSide));
        queue_pop(&outSide);
    }
    
    return 0;
}