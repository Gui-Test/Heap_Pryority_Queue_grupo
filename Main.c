#include <stdio.h>
#include <stdlib.h>
#include "arq_publico.h"
// Compilar: gcc Arvore_Heap.c arq_publico.h Main.c

int main()
{
    Heap *heap = criaHeap(10);
    info vet[]={{300,2,"Rene","Quimica"},{250,2,"Guilherme","Direito"},{100,2,"Andre","Sociologia"},{50,2,"Felipe","Engenharia Aeroespacial"},
        {1,1,"Caio","Computação"},{10,2,"Lanna","Poesia"},{20,2,"Joao","Biologia"},
        {400,2,"Rangel","Exercito"}, {-1,-1,"\0"}};

    insereHeap(heap, vet[0]);
    insereHeap(heap, vet[1]);
    insereHeap(heap, vet[2]);
    insereHeap(heap, vet[3]);
    insereHeap(heap, vet[4]);
    insereHeap(heap, vet[5]);
    insereHeap(heap, vet[6]);
    insereHeap(heap, vet[7]);

    printf("Max Heap array: ");
    printHeap(heap);

    printf("Extracted max value: %d\n", extraiMax(heap));
    printf("Max Heap array after extraction: ");
    printHeap(heap);

    free(heap->array);
    free(heap);
    return 0;
}