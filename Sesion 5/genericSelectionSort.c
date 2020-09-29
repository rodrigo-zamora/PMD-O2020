#include <stdio.h>

struct Alumno{
    int id;
    int id_grupo;
    char calificacion;
};

int compareAlumnos(void* a_ref, void* b_ref){

    struct Alumno* alumnoA = a_ref;
    struct Alumno* alumnoB = b_ref;

    if(alumnoA -> id_grupo == alumnoB -> id_grupo){
        if(alumnoA -> calificacion > alumnoB -> calificacion){
            return 1;
        }
        else if(alumnoA -> calificacion == alumnoB -> calificacion){
            return 0;
        }
        else{
            return -1;
        }
    }
    else if(alumnoA -> id_grupo > alumnoB -> id_grupo){
        return 1;
    }
    else{
        return -1;
    }

}

int compareIntegers(void* a_ref, void* b_ref){

    int* intPtrA = a_ref;
    int a = *intPtrA;

    int* intPtrB = b_ref;
    int b = *intPtrB;

    if(a > b){
        return 1;
    }
    else if(a == b){
        return 0;
    }
    else{
        return -1;
    }
}

void genericSelectionSort(void* target[], int elementCount, int(*comp)(void*, void*)){
    int i, j, min_idx;
    for(i = 0; i < elementCount-1; i++){
        min_idx = i;
        for(j = i+1; j < elementCount; j++){
            if(comp(target[j], target[min_idx]) < 0){
                min_idx = j;
            }
        }
        void* temp = target[min_idx];
        target[min_idx] = target[i];
        target[i] = temp;
    }
}

int main() {

    struct Alumno alumnos[] = {
            {683076, 1, 'F'},
            {123132, 1, 'A'},
            {145846, 3, 'A'},
            {486154, 2, 'B'},
            {841568, 1, 'A'},
            {154877, 1, 'A'}
    };

    void* direccionesAlumnos[] = {
            alumnos,
            alumnos+1,
            alumnos+2,
            alumnos+3,
            alumnos+4,
            alumnos+5
    };

    for(int i=0; i<6; i++) {
        struct Alumno* a = direccionesAlumnos[i];
        printf("ID: %d [%d] - <%c> \n", a->id, a->id_grupo, a->calificacion);
    }

    printf("-----------------------------\n");
    genericSelectionSort(direccionesAlumnos, 6, compareAlumnos);

    for(int i=0; i<6; i++) {
        struct Alumno* b = direccionesAlumnos[i];
        printf("ID: %d [%d] - <%c> \n", b->id, b->id_grupo, b->calificacion);
    }

    return 0;
}
