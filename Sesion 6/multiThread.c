//No compilable en Windows

#include <stdio.h>
#include <pthread.h>

#define POOL_SIZE 5

void* threadHandler(void* args){

  int* a = args;
  printf("Hello from thread %d!\n", *a);

  return NULL;
}

int main(void) {
  
  pthread_t thread[POOL_SIZE];
  int args[POOL_SIZE];

  for(int i=0; i<POOL_SIZE; i++){
    args[i] = i;
    int res = pthread_create(&thread[i], NULL, threadHandler, args+i);
    
    if(res){
    return res;
    }
  }

  for(int i=0; i<POOL_SIZE; i++){
    pthread_join(thread[i], NULL);
    printf("from main, %d thread finished!\n", i);
  }

  printf("Hello from main!\n");

  return 0;
}