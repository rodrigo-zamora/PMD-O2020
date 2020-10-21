#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    FILE* textFile = fopen("textFile", "w+");
    FILE* binFile = fopen("binFile.bin", "wb+");

    int someNum = 65;
    char* someText = "ABCDE";

    fprintf(textFile, "%d", someNum);
    fwrite(someText, sizeof(char), strlen(someText), binFile);

    fclose(textFile);
    fclose(binFile);
}