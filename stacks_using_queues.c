#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->data = (int*)malloc(q->capacity * sizeof(int));
    return q;
}

void enqueue(Queue *q, int item){
    if (q->size == q->capacity){
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}
int dequeue(Queue *q){
    if (q->size == 0){
        printf("Queue is empty\n");
        return -1;
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

typedef struct{
    Queue *q;
} Stack;

Stack* createStack(int capacity){
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->q = createQueue(capacity);
    return s;
}

void push(Stack *s, int item){
    int n = s->q->size;
    enqueue(s->q, item);
    for (int i = 0; i < n; i++){
        int temp = dequeue(s->q);
        enqueue(s->q, temp);
    }
}

int pop(Stack *s){
    if (s->q->size == 0){
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue(s->q);
}

int top(Stack *s){
    if (s->q->size == 0){
        printf("Stack is empty\n");
        return -1;
    }
    return s->q->data[s->q->front];
}

int main(){
    Stack *s = createStack(5);
    push(s, 10);
    push(s, 20);
    push(s, 30);
    printf("Stack top: %d\n",top(s));
    printf( "Pop: %d\n",pop(s));
    printf("New stack top: %d\n",top(s));
    return 0;
}