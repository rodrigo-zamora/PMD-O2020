#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
};

typedef struct Node* Node_ref;

// Crea un nuevo nodo con valor 'value' y retorna la referencia.
Node_ref newNode(int value);

// Imprime todos los valores de la lista
void PrintList(Node_ref node);

// Imprime todos los valores de la lista en orden inverso
void PrintListReverse(Node_ref node);

// libera la memoria de todos los elementos de una lista exceptuando el primero (first)
void DestroyList(Node_ref first);

// Agrega un nodo 'newNode' a la lista
void AddNode(Node_ref node, Node_ref newNode);

// Elimina el nodo 'nodeToRemove' de la lista, regresa 1 si se eliminó, 0 si no se eliminó.
int RemoveNode(Node_ref node, int nodeValue);

int RemoveNodeSolved(Node_ref *head, int nodeValue);

// Agrega un elemento al principio de la lista
void AddToBeginning(Node_ref* first, Node_ref nodeToAdd);

int Exists(Node_ref first, int nodeValue);

int Search(Node_ref first, int nodeValue);

int main()
{

  // Generamos el nodo inicial de la lista

  Node_ref first_ref = newNode(5);


  AddNode(first_ref, newNode(12));
  AddNode(first_ref, newNode(13));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(5));
  printf("\n");

  PrintList(first_ref); // [25]->[12]->[13]->[5]->[-123]

  printf("\nNodos eliminados con el valor 5: %d\n", RemoveNodeSolved(&first_ref, 5));

  PrintList(first_ref);  
  printf("\n");
  PrintListReverse(first_ref); // [-123]->[13]->[12]->[25]
  printf("\n");
  AddToBeginning(&first_ref, newNode(52));
  PrintList(first_ref);  
  printf("\n");
  
  int doesExist = Exists(first_ref, 25);
  if(doesExist == 1)
    printf("Si existe el 25!\n");
  else
    printf("No existe el 25!\n");
  
  doesExist = Exists(first_ref, 5);
  if(doesExist == 1)
    printf("Si existe el 5!\n");
  else
    printf("No existe el 5!\n");

  int searchNodeValue = Search(first_ref, 25);
  if(searchNodeValue > 0){
    printf("25 existe en %d\n", Search(first_ref, 25));
  }
  else{
    printf("25 no existe\n");
  }
  
  PrintList(first_ref);
  printf("\n");  
  DestroyList(first_ref); // libera la memoria de los nodos adicionales 
  PrintList(first_ref);  
  return 0;
}

Node_ref newNode(int value)
{
  Node_ref new = malloc(sizeof(struct Node));
  if(new == NULL)
    exit(EXIT_FAILURE);
  new->value = value;
  new->next = NULL;
  return new;
}

void PrintList(Node_ref node)
{
  while(node != NULL)
  {
    printf("[%d]->", node->value);
    node = node->next;
  }
}

void AddNode(Node_ref first, Node_ref newNode)
{
  while(first->next != NULL){
    first = first->next;
  }
  first->next = newNode;
  newNode->next = NULL;
}

/*Está garantizado que nodeValue existe en
la lista y es un elemento único
y no es first*/

//TAREA: Implementar removeNode sin restricciones

int RemoveNodeSolved(Node_ref *head, int nodeValue){
  
  Node_ref focusNode = *head;

  int totalRemoved = 0;

  while((*head) != NULL && (*head)->value == nodeValue)
  {
    Node_ref toDelete = (*head);
    (*head) = (*head)->next;
    free(toDelete);
    totalRemoved++;
  }

  while(focusNode != NULL)
  {
    if(focusNode->next != NULL && focusNode->next->value == nodeValue)
    {
      Node_ref nodeToRemove = focusNode->next;
      focusNode->next = focusNode->next->next;
      free(nodeToRemove);
      totalRemoved++;
    }
    else
    {
      focusNode = focusNode->next;
    }
  }

  return totalRemoved;

}

int RemoveNode(Node_ref first, int nodeValue)
{
  int contadorNodos = 0;
  if(first != NULL){
    Node_ref nodeToRemove;
    Node_ref before = NULL;

    nodeToRemove = first;

    while(nodeToRemove != NULL && nodeToRemove->value != nodeValue){
      before = nodeToRemove;
      nodeToRemove = nodeToRemove->next;
    }

    if(before != NULL){
      before->next = nodeToRemove->next;
      contadorNodos++;
      free(nodeToRemove);
    }

  }
  return contadorNodos;
}

void PrintListReverse(Node_ref node)
{
  if(node != NULL){
    PrintListReverse(node->next);
    printf("[%d]->", node->value);
  }
}

void DestroyList(Node_ref node)
{
  if(node->next != NULL){
    DestroyList(node->next);
    free(node->next);
    node->next = NULL;
  }
}

void AddToBeginning(Node_ref* head, Node_ref nodeToAdd){
  Node_ref temp = *head;
  *head = nodeToAdd;
  (*head)->next = temp;
  /*printf("----------[DENTRO DE ADD]----------\n");
  PrintList(*head);
  printf("\n----------[DENTRO DE ADD]----------\n");*/
}

int Exists(Node_ref first, int nodeValue){
  // Regresa 1 si el elemento está presente, 0 si no existe
  while(first != NULL)
  {
    if(first->value == nodeValue){
      return 1;
    }
    first = first->next;
  }
  return 0;
}

int Search(Node_ref first, int nodeValue){
  // Regresa el indice de nodeValue (el primero que encuentre) o -1 si no existe
  int contador = 0;
  while(first != NULL)
  {
    if(first->value == nodeValue){
      return contador;
    }
    first = first->next;
    contador++;
  }
  if(contador>=0){
    contador = -1;
    return contador;
  }
}