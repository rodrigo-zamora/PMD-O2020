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
int RemoveNode(Node_ref *node, int nodeValue);

int Exists (Node_ref first, int nodeValue);

int Search (Node_ref first, int nodeValue);

int main()
{
  // Generamos el nodo inicial de la lista
  Node_ref first_ref = newNode(5);

  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(5));
  AddNode(first_ref, newNode(5));

  int removed = RemoveNode(&first_ref, 5);
  printf("Removed %d nodes\n", removed);
  PrintList(first_ref);
  DestroyList(first_ref); // libera la memoria de los nodos adicionales
  printf("\n");
  return 0;
}

struct Node* newNode(int value)
{
  Node_ref new = malloc(sizeof(struct Node));
  if(new == NULL)
    exit(EXIT_FAILURE);
  new->value = value;
  new->next = NULL;
  return new;
}

void PrintList(Node_ref first)
{
  while(first != NULL)
  {
    printf("[%d]->", first->value);
    first = first->next;
  }
}

void PrintListReverse(Node_ref first)
{
  if(first->next != NULL)
  {
    PrintListReverse(first->next);
  }
  printf("[%d]->", first->value);

}

void DestroyList(Node_ref first)
{
  if(first != NULL)
  {
    DestroyList(first->next);
    free(first);
    first = NULL;
  }

}

void AddNode(Node_ref first, Node_ref newNode)
{
  while(first->next != NULL)
  {
    first = first->next;
  }
  first->next = newNode;
}

int RemoveNode(Node_ref* head, int nodeValue)
{
  // que hacemos aqui?
  // vamos a ignorar el caso donde tenemos que eliminar head
  Node_ref nodeToRemove = NULL;
  int nDelete = 0;

  while((*head) != NULL && (*head)->value == nodeValue)
  {
    // Tenemos que "decir" que head ya no es nuestro inicio
    // borrar head
    nodeToRemove = (*head);
    (*head) = (*head)->next;
    free(nodeToRemove);
    nDelete++;
  }

  Node_ref focusNode = *head;
  while(focusNode != NULL)
  {
    if(focusNode->next != NULL && focusNode->next->value == nodeValue)
    {
      nodeToRemove = focusNode->next;
      focusNode->next = focusNode->next->next;
      free(nodeToRemove);
      nDelete++;
    } else {
      focusNode = focusNode->next;
    }
  }

  return nDelete;
}
