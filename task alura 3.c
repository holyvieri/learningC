#include<stdio.h>
#include<stdlib.h>
// não consegui incluir a função abs por mais q n precise, mas queria
int main()
{
    int n;

    printf("Which multiplication table do u wanna see? \n");
    scanf("%d", &n);

    for(int i= 1; i<=10; i++)
    {
        int r;
        r=n*i;
        printf("%d x %d = %d \n", n, i, r);
    }
    
}