// leet code problem no 32 in c
// tried and tested on leetcode

#include<stdio.h>
#include<string.h>

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if(n==0)
    {
        return 0;
    }
    
    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int left = 0;
        int right = 0;
        for(int j=i;j<n;j++)
        {
            if(s[j]=='(')
            {
                left++;
            }
            else{
                right++;
            }
            if(right>left)
            {
                break;
            }
            if(left == right && left+right>ans)
            {
                ans = left+right;
            }
        }
    }
    return ans;
} 

int main()
{
    char arr1[] = "(((())))";
    char arr2[] = "()()(()()";

    printf("%d %d\n",longestValidParentheses(arr1),longestValidParentheses(arr2));
}