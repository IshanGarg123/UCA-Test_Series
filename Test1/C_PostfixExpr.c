#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1000];
int index1 = -1;

void push(int x)
{
    index1++;
    arr[index1] = x;
}

void pop()
{
    if(index1 == -1)
    {
        return;
    }
    index1--;
}

int top()
{
    if(index1 == -1)
    {
        return -1;
    }
    return arr[index1];
}

int stoi(char arr[])
{
    int len = strlen(arr);
    int temp = 0;
    for(int i=0;i<len;i++)
    {
        temp = temp*10 + (int)(arr[i]-'0');
    }
    return temp;
}

int main() {
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        char temp[100];
        index1 = -1;
        int temp1=0,temp2=0;
        
        while(true)
        {
            scanf("%s",&temp);
            if(temp[0] == '?')
            {
                break;
            }
            else if(temp[0] == '+')
            {
                temp1 = top();
                pop();
                temp2 = top();
                pop();
                push(temp2+temp1);
            }
            else if(temp[0] == '-')
            {
                temp1 = top();
                pop();
                temp2 = top();
                pop();
                push(temp2-temp1);
                
            }
            else if(temp[0] == '*')
            {
                temp1 = top();
                pop();
                temp2 = top();
                pop();
                push(temp2*temp1);
            }
            else if(temp[0] == '/')
            {
                temp1 = top();
                pop();
                temp2 = top();
                pop();
                push(temp2/temp1);      
            }
            else{
                temp1 = stoi(temp);
                push(temp1);
            }
        }
        printf("%d\n",arr[0]);
    }
    return 0;
}