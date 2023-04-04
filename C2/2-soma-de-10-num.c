#include<stdio.h>

void abertura(int numbers[]){
    printf("Tell me ten positives numbers pls\n");
    for(int i=0; i <10; i++){
        scanf(" %d", &numbers[i]);
    }

}
int main (){ 
    int numbers[10];
    abertura(numbers);

    int sum=0;
    for (int i = 0; i < 10; i++){
        sum+= numbers[i];
    }
    
    printf("The sum of the ten numbers is: %d\n", sum);
    return 0;
}