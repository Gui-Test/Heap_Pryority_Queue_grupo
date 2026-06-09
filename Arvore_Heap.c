#include "arq_publico.h"
// Estrutura de um Max-heap

// Função que cria um heap
Heap *criaHeap(int capacity)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (info *)malloc(capacity * sizeof(info));
    return heap;
}

// Função que troca 2 info
void troca(info *a, info *b)
{
    info temp = *a;
    *a = *b;
    *b = temp;
}

// Função que heapfica um nó no index i
void heapfica(Heap *heap, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left].matricula > heap->array[largest].matricula)
        largest = left;

    if (right < heap->size && heap->array[right].matricula > heap->array[largest].matricula)
        largest = right;

    if (largest != i)
    {
     troca(&heap->array[i], &heap->array[largest]);
        heapfica(heap, largest);
    }
}

// Função que heapfica um array já existente
void buildHeap(Heap *heap)
{
    int n = heap->size;
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapfica(heap, i);
}

// Função que aumenta o valor da chave de um index
void aumentaChave(Heap *heap, int index, int newValue)
{
    if (index >= heap->size || heap->array[index].matricula >= newValue)
    {
        printf("Invalid index or new value is not greater\n");
        return;
    }

    heap->array[index].matricula = newValue;
    while (index != 0 && heap->array[(index - 1) / 2].matricula < heap->array[index].matricula)
    {
     troca(&heap->array[index], &heap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Função que insere um valor novo no heap
int insereHeap(Heap *heap, info value)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap overflow\n");
        return FRACASSO;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    // Conserta propriedade Heap se violada
    while (i != 0 && heap->array[(i - 1) / 2].matricula < heap->array[i].matricula)
    {
     troca(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
    return SUCESSO;
}

// Função que deleta uma chave
void deletaChave(Heap *heap, int index)
{
    if (index >= heap->size)
    {
        printf("Invalid index\n");
        return;
    }

    if (index == heap->size - 1)
    {
        heap->size--;
        return;
    }

    heap->array[index] = heap->array[heap->size - 1];
    heap->size--;
    heapfica(heap, index);
}

// Função que printa heap
void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->array[i].matricula);
    printf("\n");
}

// Função que extrai a raiz(elemento máximo)
int extraiMax(Heap *heap)
{
    if (heap->size <= 0)
        return INT_MIN;
    if (heap->size == 1)
    {
        heap->size--;
        return heap->array[0].matricula;
    }

    int root = heap->array[0].matricula;
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapfica(heap, 0);

    return root;
}


