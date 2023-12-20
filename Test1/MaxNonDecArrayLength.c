// leet code problem no 2945 in c
// it is failed on leet code 
// unable to run all test cases

#include<stdio.h>
int findMaximumLength(int *nums, int n)
{
    int ans = 1;
    int temp = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (temp < nums[i])
        {
            ans++;
            temp = nums[i];
        }
        else
        {
            if (i == n - 1)
            {
                return ans;
            }
            nums[i + 1] += nums[i];
        }
    }
    return ans;
}

int main()
{
    printf("Find Maximum Non-decreasing Array Length");
    return 0;
}