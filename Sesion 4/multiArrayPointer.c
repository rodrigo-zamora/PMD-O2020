#include <stdio.h>

void printDictionary(char** , int);
int main(void)
{
  /*
  int someVar = 0;
  int foo[3]={3,4,5};
  int bar[3]={7,10,9};
  // vaz es un ARREGLO DE APUNTADORES AKA Matrix
  // Baz en su subíndice 0 APUNTE a foo
  int bBaz[3][3];
  int* baz[] = {foo, bar, &someVar};
  int** a = baz;
  //printf("%d\n", foo[0]); // -> 3
  //printf("%d\n", baz[0][1]); // -> 4
  printf("%d\n", a[1][0]);
  printf("%d\n", *a[1]);
  //printf("%d\n", *(*(a+1)+1));
  //printf("%d\n", *(*(a+1)+1)); //10
  //printf("%d\n", *(*(baz)+1)); //4
  //printf("%d\n", *(*(baz+1))); //7
  */

  char* arry[] = {
    "hola",
    "mundo",
    "adios"
  };

  printDictionary(arry, 3);
}


// Imprime cada cadena dentro de input
// hola
// mundo
// adios
void printDictionary(char** input, int n)
{
  for(int i=0; i < n; i++)
  {
    // como obtenemos las cadenas?
    for(int j=0; *(input[i]+j) != '\0'; j++)
    {
      // com obtenemos los caracteres
      printf("char");
    }
  }
}