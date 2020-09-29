#include <stdio.h>
#include <stdlib.h>

int suma(int* a, int* b){

    int resultado = *a + *b;
    return resultado;

}

char* Foo(){

    char* saludo = malloc(5 * sizeof(char));

}

int main(void){
    int a = 12;
    int b = 10;

    suma(&a, &b);

    return 0;
}