#include "map.h"

Node* newNode(char* key, char* value)
{
    Node* n = malloc(sizeof(Node));
    n->key = key;
    n->value = value;
    n->next = NULL;
    return n;
}

Map* mapCreate(int tableSize, int (*HashFunction)(char*))
{
    Map* m = malloc(sizeof(Map));
    m->tableSize = tableSize;
    m->hashTable = calloc(tableSize, sizeof(Node));
    m->HashFunction = HashFunction;

    return m;
}

void mapPut(Map* m, char* key, char* value)
{
    int hashKey = m->HashFunction(key) % m->tableSize;
    
    if(m->hashTable[hashKey] == NULL){
        m->hashTable[hashKey] = newNode(key, value);
    } else {
        Node* focusNode = m->hashTable[hashKey];
        while(focusNode->next != NULL){
            if(strcmp(focusNode->key, key) == 0){
                return;
            }
        }
        if(strcmp(focusNode->key, key) == 0){
            return;
        }
    }
}

char* mapGet(Map* m, char* key)
{
    int hashKey = m->HashFunction(key) % m->tableSize;
    return m->hashTable[hashKey]->value;
}

int mapContains(Map* m, char* key);