#include "Map.h"

Node* newNode(char* key, char* value)
{
  Node* n = malloc(sizeof(Node));
  n->key = key;
  n->value = value;
  n->next = NULL;
  return n;
}

Map* map_create(int tableSize, int (*HashFunction)(char*))
{
  Map* m = malloc(sizeof(Map));

  m->tableSize = tableSize;
  m->hashTable = calloc(tableSize, sizeof(Node)); // ?
  m->HashFunction = HashFunction;

  return m;
}

// Esto agrega el par de <key, value> al mapa.
// <omg, oh my god>

void map_put(Map* m, char* key, char* value)
{
  int hashKey = m->HashFunction(key) % m->tableSize;
  // tenemos que manejar colisiones!

  if(m->hashTable[hashKey] == NULL)
  {
    m->hashTable[hashKey] = newNode(key, value);
  } else {
    // hashKey ya fue asignado!
    // que ya exista la llave key en el mapa?
    // que ocurra una colision?
    Node* focusNode = m->hashTable[hashKey];
    while(focusNode->next != NULL)
    {
      if(strcmp(focusNode->key, key) == 0) {
        m->hashTable[hashKey]->value++;
        return;
      }
      focusNode = focusNode->next;
    }
    if(strcmp(focusNode->key, key) == 0){
        *(focusNode->value)++;
      return;
    }
    // si llegamos esta parte del ciclo
    // es un nodo valido, pero tenemos que manejar la colision
    printf("Colision detectada al agregar: %s\n", key);
    focusNode->next = newNode(key, value);
  }
}

// map_get(m, "omg") -> "oh my god"
char* map_get(Map* m, char* key)
{
  int hashKey = m->HashFunction(key) % m->tableSize;

  Node* focusNode = m->hashTable[hashKey];
  if(focusNode == NULL)
    return NULL;

  while(focusNode != NULL)
  {
    if(strcmp(focusNode->key, key) == 0)
      return focusNode->value;
    focusNode = focusNode->next;
  }
  // aqui que regresamos?
  return NULL;
}

// regresa 1 si la llave existe en el mapa, 0 de otra forma
int map_contains(Map* m, char* key) { return map_get(m, key) != NULL; }