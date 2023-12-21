#include<stdio.h>

int bitAnd (int x, int y) {
    return ~(~x | ~y);
}

int bitXor (int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}


int main()
{
    printf("%d %d %d %d\n",bitAnd(0,0),bitAnd(1,0),bitAnd(0,1),bitAnd(1,1));
    printf("%d %d %d %d\n",bitXor(0,0),bitXor(1,0),bitXor(0,1),bitXor(1,1));
    return 0;
}