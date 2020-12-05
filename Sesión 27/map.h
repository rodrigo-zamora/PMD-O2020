#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef HASHMAP_MAP_H
#define HASHMAP_MAP_H

typedef struct node
{
    char* key;
    char* value;
    struct node* next;
}Node;

typedef struct map
{
    Node** hashTable;
    int tableSize;
    int (*HashFunction)(char*);
}Map;


Map* mapCreate(int tableSize, int (*HashFunction)(char*)); // Crear el mapa
void mapPut(Map* m, char* key, char* value); // Agrega elementos al set
char* mapGet(Map* m, char* key); // Obtiene elementos al set
int mapContains(Map* m, char* key); // Revisar si un elemento existe dentro del mapa

#endif //HASHMAP_MAP_H