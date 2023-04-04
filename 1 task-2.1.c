#include<stdio.h>

int main() 
{
    printf("Here it is:\n");

    int x=1;
    int r=0;

    while (x <= 100) 
    {
        r = r + x;  
        x++;
    }

    printf("1+2+3+4+...+100 = %d", r);
}
