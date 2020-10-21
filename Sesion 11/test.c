#include <stdio.h>
#include <stdlib.h>

int main(){
    int* arry= calloc(10, sizeof(int));
    for(int i = 0; i < 10; i++){
        arry[i] = i;
        printf("%d ", arry[i]);
    }
    
    

    free(arry);
}