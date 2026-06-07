#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a Heap (Max Heap)

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

// Function to create a heap
Heap *createHeap(int capacity)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (info *)malloc(capacity * sizeof(info));
    return heap;
}

// Function to swap two integers
void swap(info *a, info *b)
{
    info temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the node at index i
void heapify(Heap *heap, int i)
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
        swap(&heap->array[i], &heap->array[largest]);
        heapify(heap, largest);
    }
}

// Function to build a max heap from an existing array
void buildHeap(Heap *heap)
{
    int n = heap->size;
    for (int i = (n - 1) / 2; i >= 0; i--)
        heapify(heap, i);
}

// Function to increase the value at a given index
void increaseKey(Heap *heap, int index, int newValue)
{
    if (index >= heap->size || heap->array[index].matricula >= newValue)
    {
        printf("Invalid index or new value is not greater\n");
        return;
    }

    heap->array[index].matricula = newValue;
    while (index != 0 && heap->array[(index - 1) / 2].matricula < heap->array[index].matricula)
    {
        swap(&heap->array[index], &heap->array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// Function to insert a new value into the heap
void insertHeap(Heap *heap, info value)
{
    if (heap->size == heap->capacity)
    {
        printf("Heap overflow\n");
        return;
    }

    heap->size++;
    int i = heap->size - 1;
    heap->array[i] = value;

    // Fix the heap property if it is violated
    while (i != 0 && heap->array[(i - 1) / 2].matricula < heap->array[i].matricula)
    {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the root (maximum element)
int extractMax(Heap *heap)
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
    heapify(heap, 0);

    return root;
}

// Function to print the heap
void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; ++i)
        printf("%d ", heap->array[i].matricula);
    printf("\n");
}

// Function to delete an element at a given index
void deleteKey(Heap *heap, int index)
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
    heapify(heap, index);
}

int main()
{
    Heap *heap = createHeap(10);
    info vet[]={{300,2,"Rene","Quimica"},{250,2,"Guilherme","Direito"},{100,2,"Andre","Sociologia"},{50,2,"Felipe","Engenharia Aeroespacial"},
        {1,1,"Caio","Computação"},{10,2,"Lanna","Poesia"},{20,2,"Joao","Biologia"},
        {400,2,"Rangel","Exercito"}, /*{272,32,"Andrea"},{392,34,"Thiagoa"},
                             {258,33,"Lucasb"},{274,32,"Andreb"},{394,34,"Thiagob"},
                             {259,33,"Lucasc"},{276,32,"Andrec"},{396,34,"Thiagoc"},
                             {1250,33,"Lucasw"},{1270,32,"Andrew"},{1390,34,"Thiagow"},
                             {2250,33,"Lucasq"},{2270,32,"Andreq"},{2390,34,"Thiagoq"},
                             {30,30,"Pedrow"},{20,32,"Paulow"},{10,35,"Judasa"},{40,31,"Manuel"},
                             {35,30,"Pedror"},{25,32,"Paulor"},{105,35,"Judase"},{405,31,"Manuele"},
                             {135,30,"Pedrore"},{125,32,"Paulore"},{1105,35,"Judasei"},{1405,31,"Manuelew"},
                             {3335,30,"Pediror"},{3325,32,"Paulior"},{33105,35,"Judasie"},{33405,31,"Manuelie"},
                             {535,30,"Wedror"},{525,32,"Pawlor"},{505,35,"Judawe"},{515,31,"Wanuele"},
                             {635,30,"Wuedror"},{625,32,"Pauwlor"},{605,35,"Judauwe"},{615,31,"Wanueule"},
                             {5,30,"Wedrori"},{7,32,"Pawlori"},{9,35,"Judawei"},{6,31,"Wanuelie"},
                             {4005,30,"Wori"},{4007,32,"Pori"},{4009,35,"Jawei"},{4006,31,"Waelie"},
                             {5300,30,"LECO"},{5200,32,"Peco"},{5100,35,"Luas"},{5400,31,"Manulo"},*/ {-1,-1,"\0"}};

    insertHeap(heap, vet[0]);
    insertHeap(heap, vet[1]);
    insertHeap(heap, vet[2]);
    insertHeap(heap, vet[3]);
    insertHeap(heap, vet[4]);
    insertHeap(heap, vet[5]);
    insertHeap(heap, vet[6]);
    insertHeap(heap, vet[7]);

    printf("Max Heap array: ");
    printHeap(heap);

    printf("Extracted max value: %d\n", extractMax(heap));
    printf("Max Heap array after extraction: ");
    printHeap(heap);

    free(heap->array);
    free(heap);
    return 0;
}