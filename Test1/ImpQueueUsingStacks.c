// leet code problem no 232 in c
// tried and tested on leetcode
// Implement Queue using Stacks
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct {
    int top;
    int *arr;
} MyStack;

MyStack* stackCreate()
{
    MyStack* stk = (MyStack*)malloc(sizeof(MyStack));
    stk->top = -1;
    stk->arr = (int*)malloc(1000*sizeof(int));
    return stk;
}

void push(MyStack* stk,int x)
{
    (stk->top)++;
    stk->arr[stk->top] = x;
}

void pop(MyStack* stk)
{
    if(stk->top == -1)
    {
        return;
    }
    (stk->top)--;
}

int getTop(MyStack* stk)
{
    if(stk->top == -1)
    {
        return -1;
    }
    return stk->arr[stk->top];
}

bool empty(MyStack* stk)
{
    return (stk->top == -1);
}

int size(MyStack* stk)
{
    return (stk->top)+1;
}


typedef struct {
    MyStack* s1;
    MyStack* s2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* q = (MyQueue*)malloc(sizeof(MyQueue));
    q->s1 = stackCreate();
    q->s2 = stackCreate(); 
    return q;
}

void myQueuePush(MyQueue* obj, int x) {
    while(!empty(obj->s1))
    {
        push(obj->s2,getTop(obj->s1));
        pop(obj->s1);
    }

    push(obj->s1,x);

    while(!empty(obj->s2))
    {
        push(obj->s1,getTop(obj->s2));
        pop(obj->s2);
    }
}

int myQueuePop(MyQueue* obj) {
    if(empty(obj->s1))
    {
        return -1;
    }
    int temp = getTop(obj->s1);
    pop(obj->s1);
    return temp;
}

int myQueuePeek(MyQueue* obj) {
    if(empty(obj->s1))
    {
        return -1;
    }
    return getTop(obj->s1);
}

bool myQueueEmpty(MyQueue* obj) {
    return empty(obj->s1);
}

void myQueueFree(MyQueue* obj) {
    free(obj->s2);
    free(obj->s1);
    free(obj);
}

int main()
{
    printf("Implement Queue using Stacks");
    return 0;
}