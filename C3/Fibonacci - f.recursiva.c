#include <stdio.h>

// função recursiva para a sequência de Fibonacci
int fibonacci(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main(){
    int qtd = 20;
    printf("*********** FIBONACCI SEQUENCE ***************\n\n");
    for (int i = 0; i < qtd; i++){
        printf("%d\n", fibonacci(i));
    }
    return 0;
}