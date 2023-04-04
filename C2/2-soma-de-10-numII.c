#include<stdio.h>

int soma (int numbers[])
{
    int r=0;
    for(int i= 0; i < 10; i++){
        r = r + numbers[i];
    }
    
    return r;
}

int main(){
    int numbers[10];
    printf("Tell me ten positive numbers pls\n");
    for (int i = 0; i < 10 ; i++){
        scanf("%d", &numbers[i]);
    }
    
    int resultado = soma(numbers);
    printf(" O total e %d\n", resultado);
    return 0;
}