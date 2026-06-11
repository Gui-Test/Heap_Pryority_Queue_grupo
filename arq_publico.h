#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0

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
void menu(Heap *heap);
void troca(info *a, info *b);
void heapfica(Heap *heap, int i);
void aumentaChave(Heap *heap, int index, int newValue);
int insereHeap(Heap *heap, info value);
void deletaChave(Heap *heap, int index);
void printHeap(Heap *heap);
void heapSort(Heap *heap);
int extraiMax(Heap *heap);
int removeItem(Heap *heap);
int buscaNaCauda(Heap *heap, info *auxInfo);
int buscaNaFrente(Heap *heap, info *auxInfo);
void reiniciaHeap(Heap *heap);

//Funções relacionadas ao CSV
void insereHeapCSV(Heap *heap, int nlinha);
