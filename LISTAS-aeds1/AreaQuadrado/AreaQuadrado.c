#include <stdio.h>
#include <stdlib.h>

int main()
{
    float lado;
    printf("Digite o lado do quadrado:   ");
    
    scanf("%f", &lado); 
    
    float resultado = lado * lado;
    
    printf("A area do quadrado e: %f", resultado); 
    
    return 0; 
}