#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
  struct Node* prev;
};

struct Stack {
  struct Node* head;
  int count;
};

struct Stack* newStack()
{
  struct Stack* newStack = malloc(sizeof(struct Stack));
  newStack->head = NULL;
  newStack->count=0;
  return newStack;
}

void Push(struct Stack* stack, struct Node* toAdd)
{
  if(stack->head == NULL)
  {
    // aqui el stack esta vacio, toAdd es el primer elemento
    stack->head = toAdd;
  } else 
  {
    // aqui el stack ya tiene datos previos
    toAdd->next = NULL;
    toAdd->prev = stack->head;
    stack->head->next = toAdd;
    // ?
    stack->head = toAdd;
  }
  stack->count++;
}

struct Node* Pop(struct Stack* stack)
{
  // regresamos HEAD, y actualizamos la lista
  // para que head->prev sea nuestro nuevo head.
  struct Node* nodeToReturn = stack->head;
  if(nodeToReturn != NULL)
  {
    stack->head = stack->head->prev;
    stack->count--;
  }

  return nodeToReturn;
}

void PrintStack(struct Stack* stack)
{
  struct Node* focusNode = stack->head;

  while(focusNode->prev != NULL)
    focusNode = focusNode->prev;
  
  while(focusNode != NULL)
  {
    printf("[%d]", focusNode->value);
    focusNode = focusNode->next;
  }
}

struct Node* newNode(int value)
{
  struct Node* new = malloc(sizeof(struct Node));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;

  return new;
}

int main()
{
  struct Stack* foostack = newStack();

  Push(foostack, newNode(2));
  Push(foostack, newNode(3));
  Push(foostack, newNode(4));

  // PrintStack(foostack);
  printf("%d\n", Pop(foostack)->value); // 4
  printf("%d\n", Pop(foostack)->value); // 3
  printf("%d\n", Pop(foostack)->value); // 2

  if(Pop(foostack) != NULL)
    printf("%d\n", Pop(foostack)->value);
  if(Pop(foostack) != NULL)
    printf("%d\n", Pop(foostack)->value);
  if(Pop(foostack) != NULL)
    printf("%d\n", Pop(foostack)->value);
  if(Pop(foostack) != NULL)
    printf("%d\n", Pop(foostack)->value);
  return 0;
}