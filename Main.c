#include <stdio.h>
#include <stdlib.h>
#include "arq_publico.h"
// Compilar: gcc Arvore_Heap.c arq_publico.h Main.c

int main()
{
    Heap *heap = criaHeap(10);
    menu(heap);
}

void menu(Heap *p)
{  
   char opc;
   info auxInfo;

   do{ 
   fflush(stdin);
   puts(" entre com uma opcao 1 (busca na frente), 2 (enfileira),");
   puts("                      3 (remove da fila),4 (busca na cauda), 5 purga");
   puts("                      \"zero\" para encerrar");
   printf("\n");
	opc = getchar();

	switch (opc)
	{ 
      case '1':
               if(buscaNaFrente(&auxInfo,p)==FRACASSO) puts("fila vazia!");
               else
                printf("\n consultado : %i \n", auxInfo.matricula);
		         break;
     case '2':
            printf("\nEntre com o numero de matricula:\n");
            fflush(stdin);
            scanf("%i", &auxInfo.matricula);
            printf("\nEntre com o ranking do aluno:\n");
            scanf("%i", &auxInfo.ranking);
            printf("\nEntre com o nome do aluno:\n");
            scanf("%i", &auxInfo.nome);
            printf("\nEntre com o curso do aluno:\n");
            scanf("%i", &auxInfo.curso);
            if(insereHeap(p, auxInfo)==FRACASSO)
             { 
               puts("erro na insercao: estrutura de dados cheia !");
             }
            break;
     case '3':

            if(remove_(&auxInfo,p)==FRACASSO) 
               puts("fila vazia!");
            else
               printf("\n item retirado : %i \n", auxInfo.matricula);
            break;
     case '4':

            if(buscaNaCauda(&auxInfo,p)==FRACASSO)
               printf("fila vazia!");
            else
               printf("\n consultado : %i \n", auxInfo.matricula);
		      break;
     case '5' :
            reinicia(p);
            puts("limpou a fila !!!");
            break;


        }
        getchar();
   }while(opc != '0');
   puts("tchau");

}
