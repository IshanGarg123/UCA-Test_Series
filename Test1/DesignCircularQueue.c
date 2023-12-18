// leet code problem no 622 in c
// tried and tested on leetcode
// Design the circular queue

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    int capacity;
    int front;
    int rear;
    int size;
    int *arr;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    q->capacity = k;
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->arr = (int*)malloc(sizeof(int)*k);
    return q;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value){
    if(obj->size < obj->capacity)
        {
            if(obj->rear == -1)
            {
                obj->front = 0;
            }
            obj->rear = (obj->rear+1)%obj->capacity;
            obj->arr[obj->rear] = value;
            (obj->size)++;
            return true;
        }
        return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
        if(obj->size == 0)
        {
            return false;
        }
        obj->front = (obj->front+1)%obj->capacity;
        (obj->size)--;
        if(obj->size == 0)
        {
            obj->front = -1;
            obj->rear = -1;
        }
        return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
        if(obj->front == -1)
        {
            return -1;
        }
        return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
        if(obj->rear == -1)
        {
            return -1;
        }
        return obj->arr[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->size == 0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->size == obj->capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

int main()
{
    printf("Design Circular Queue");
    return 0;
}