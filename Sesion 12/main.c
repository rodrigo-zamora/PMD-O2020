#include <stdio.h>
#include <stdlib.h>

void writeNumbers(int start, int end, FILE* stream);
void consoleWriteNumbers(int start, int end);
void readNumbersFromStream(FILE* stream);

int main(){
    FILE* f;
    f = fopen("numbers", "a");
    consoleWriteNumbers(5, 10);
    writeNumbers(1, 10, f);
    rewind(f);
    readNumbersFromStream(f);
}

void consoleWriteNumbers(int start, int end){
    for(int i = start; i <= end; i++){
        fprintf(stdout, "%d\n", i);
    }
}

void writeNumbers(int start, int end, FILE* stream){
    for(int i = start; i <= end; i++){
        fprintf(stream, "%d\n", i);
    }
}

void readNumbersFromStream(FILE* stream){
    int readNumber, sum = 0;
    while(fscanf(stream, "%d\n", &readNumber) != EOF){
        sum += readNumber;
        printf("Leimos [%d] y el agregado es [%d]\n", readNumber, sum);
    }
}