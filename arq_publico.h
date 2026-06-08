#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef int tipoChave;

typedef struct{ 
    tipoChave matricula;
    int ranking;
    char nome[30];
    char curso[30];
}info;

typedef struct Heap
{
    info *array;
    int size;
    int capacity;
} Heap;

//Funções do Heap
Heap *criaHeap(int capacity);
void troca(info *a, info *b);
void heapfica(Heap *heap, int i);
void aumentaChave(Heap *heap, int index, int newValue);
void insereHeap(Heap *heap, info value);
void deletaChave(Heap *heap, int index);
void printHeap(Heap *heap);
int extraiMax(Heap *heap);