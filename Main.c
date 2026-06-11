#include <stdio.h>
#include <stdlib.h>
#include "arq_publico.h"
// Compilar: gcc Arvore_Heap.c arq_publico.h Main.c

int main()
{
    Heap *heap = criaHeap(10);
    menu(heap);
}

void menu(Heap *heap)
{  
   char opc;
   info auxInfo;

   do{ 
      fflush(stdin);
      puts("Entre com uma opcao:");
      puts("1 - Busca na frente");
      puts("2 - Insere");
      puts("3 - Remove da fila");
      puts("4 - Busca na cauda");
      puts("5 - Reinicia");
      puts("6 - Enfileira");
      puts("\"zero\" para encerrar");
      printf("\n");
      printf("Digite a opção: ");
      opc = getchar();
      printf("\n");

      switch (opc)
      { 
         case '1':
               if(buscaNaFrente(heap,&auxInfo)==FRACASSO){
                  printf("fila vazia!\n");
                  printf("\n");
               }
               else{
                  printf("Informações da frente \n");
                  printf("Nome: %s\n", auxInfo.nome);
                  printf("Matricula: %i\n",auxInfo.matricula);
                  printf("Curso: %s\n",auxInfo.curso);
                  printf("Ranking: %i\n",auxInfo.ranking);
                  printf("\n");
               }
               break;
         case '2':
               printf("\nEntre com o numero de matricula:\n");
               fflush(stdin);
               scanf("%i", &auxInfo.matricula);
               printf("\nEntre com o ranking do aluno:\n");
               scanf("%i", &auxInfo.ranking);
               printf("\nEntre com o nome do aluno:\n");
               scanf("%s", auxInfo.nome);
               printf("\nEntre com o curso do aluno:\n");
               scanf("%s", auxInfo.curso);
               if(insereHeap(heap, auxInfo)==FRACASSO)
               { 
                  puts("erro na insercao: estrutura de dados cheia !");
               }else puts("Inserido com sucesso");
               break;
         case '3':

               if(heap->size == 0) 
                  puts("fila vazia!");
               else
                  auxInfo.matricula = removeItem(heap);
                  printf("\n item retirado : %i \n", auxInfo.matricula);
               break;
         case '4':

               if(buscaNaCauda(heap,&auxInfo)==FRACASSO)
                  printf("fila vazia!\n");
               else
                  printf("Informações da cauda \n");
                  printf("Nome: %s\n", auxInfo.nome);
                  printf("Matricula: %i\n",auxInfo.matricula);
                  printf("Curso: %s\n",auxInfo.curso);
                  printf("Ranking: %i\n",auxInfo.ranking);
                  printf("\n");
               break;
         case '5' :
               reiniciaHeap(heap);
               puts("limpou a fila !!!");
               printf("\n");
               break;
         case '6' :
               puts("Fila enfileirada (Ordem Crescente)");
               printf("\n");
               heapSort(heap);
               printf("\n");
               break;
         default: 
               puts("Opção inválida");
               break;
         }
         
         getchar();
   }while(opc != '0');
   puts("tchau");

}
