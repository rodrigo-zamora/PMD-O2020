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
    Map* m = mapCreate(12, hashString);
    printf("Hashkey para %s es %d\n", "hola", hashString("hola")); 
    printf("Hashkey para %s es %d\n", "hola mundo", hashString("hola mundo"));   
    return 0;
}