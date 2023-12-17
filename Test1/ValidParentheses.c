// leet code problem no 20 in c
// tried and tested on leetcode

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

char arr[10000];
int index1;

void push(char ch)
{
    index1++;
    arr[index1] = ch;
}

void pop()
{
    if(index1 == -1)
    {
        return;
    }
    index1--;
}

char top()
{
    if(index1 == -1)
    {
        return ' ';
    }
    return arr[index1];
}

bool isEmpty()
{
    if(index1 == -1)
    {
        return true;
    }
    return false;
}

int size()
{
    return index1+1;
}

void printArray()
{
    for(int i=0;i<=index1;i++)
    {
        printf("%c ",arr[i]);
    }
    printf("\n");
}

bool isValid(char* s) {
    int len = strlen(s);
    index1 = -1;

    for(int i=0;i<len;i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            push(s[i]);
        }
        else{
            if((s[i] == ')' && top() == '(') || (s[i] == ']' && top() == '[') ||    (s[i] == '}' && top() == '{'))
            {
                pop();
            }
            else{
                return false;
            }
        }
        // printArray();
    }
    if(isEmpty())
    {
        return true;
    }
    return false;   
}

int main()
{
    char arr[] = "{[{{}()}]}";
    char arr1[] = "{[][]())";

    printf("%d\n",isValid(arr));
    // true

    printf("%d\n",isValid(arr1));
    //false
}