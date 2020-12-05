// Rodrigo Zamora Dávalos
// Ernesto Benjamin Vázquez Cruz
// José Jaime Gutiérrez Martínez
// Vania Paola Zúñiga Salazar
#include <stdio.h>
#include "map.h"

int hashString(char* string)
{
    int len = strlen(string);
    int hashKey = 0;

    for(int i = 0; i < len; i++){
        hashKey+= string[i] - 'a';
    }

    return hashKey;
}

int main()
{
    //Map* m = mapCreate(1000000, hashString);
    int n1, n2, n3, n4;
    //printf("most common: %d\n", most_common("networkTrace.txt"));
    FILE* network = fopen("networkTrace.txt", "r");

    //char a[25] = fscanf(network, "%d.%d.%d.%d", &n1, &n2, &n3, &n4);
    /*float a[25];
    for ( int i = 0; i < 25; i++){
        fscanf(network, "%f", &a[i]);
    }
    for ( int i = 0; i < 59; i++) {
           printf("Number is: %f\n\n", a[i]);
    }*/

    char readNumber[20];

    /*char buffer[20];
    while(fgets(buffer, 19, network) != NULL){

    }*/

    while (fscanf(network, "%s\n", &readNumber) != EOF)
    {
        printf("Numero leido: %s\n", readNumber);
        int count = 0;
        /*if(readNumber == '.'){
            count++;
        }
        if (count == 3){
            printf("Numero leido: %s\n", readNumber);
        }*/
        //fseek(network, 7, SEEK_SET);
        /*for(int i = 0; &readNumber <= '\0'; i++){

            
        }*/
    }
    

    
    


    // while(a[25] != EOF){
    //     printf("%d\n", n4);
    // }
    //printf("Hashkey para %s es %d\n", "hola", hashString("hola")); 
    fclose(network);
}
