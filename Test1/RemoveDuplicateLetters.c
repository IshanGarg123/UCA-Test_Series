// leet code problem no 316 in c
// tried and tested on leetcode
// Remove Duplicate Letters

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
    int top;
    char *arr;
} MyStack;

MyStack* stackCreate()
{
    MyStack* stk = (MyStack*)malloc(sizeof(MyStack));
    stk->top = -1;
    stk->arr = (char*)malloc(26*sizeof(char));
    return stk;
}

void push(MyStack* stk,char x)
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

char getTop(MyStack* stk)
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

void printStack(MyStack* stk)
{
    for(int i=0;i<=stk->top;i++)
    {
        printf("%c ",stk->arr[i]);
    }
    printf("\n");
}

void reverse(char* ans)
{
    int i = 0;
    int j = strlen(ans)-1;

    while(j>i)
    {
        char temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        i++;
        j--;
    }
}

char* removeDuplicateLetters(char* s) {
    bool isPresent[26];
    int lastIndex[26];
    for(int i=0;i<26;i++)
    {
        isPresent[i] = false;
        lastIndex[i] = -1;
    }

    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        lastIndex[s[i]-'a'] = i;
    }

    MyStack* stk = stackCreate();
    //printStack(stk);

    for(int i=0;i<len;i++)
    {
        if(isPresent[s[i]-'a'])
        {
            continue;
        }
        while(!empty(stk))
        {
            if(getTop(stk) < s[i])
            {
                break;
            }
            else{
                char temp = getTop(stk);
                if(lastIndex[temp-'a'] > i)
                {
                    pop(stk);
                    isPresent[temp-'a'] = false;
                }
                else{
                    break;
                }
            }
        }
        push(stk,s[i]);
        isPresent[s[i]-'a'] = true;
        //printStack(stk);
    }

    // string ans="";
    char ans[30];
    int index = 0;
    while(!empty(stk))
    {
        ans[index] = getTop(stk);
        index++;
        pop(stk);
    }
    ans[index] = '\0';
    free(stk);
    //printf("%s\n",ans);
    reverse(ans);
    //printf("%s\n",ans);
    char* result = ans;
    return result;
}


int main()
{
    printf("Remove Duplicate Letters");
    return 0;
}