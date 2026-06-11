#include "arq_publico.h"

void insereHeapCSV(Heap *heap, int nlinha){
    FILE *f = fopen("dataset_v1.csv", "r");
    info infoAux;
    if(!f){
        printf("Arquivo não encontrado.\n");
        return;
    }
   
        char linha[1024];
        fgets(linha, 1024, f);
        for(int i = 0;i < nlinha;i++) {
            fgets(linha, 1024, f);    
        }
        if(!feof(f)){
            printf("Linha lida: %s", linha);
            // 3. Dividir a linha usando a vírgula (',') como delimitador
            char *campo = strtok(linha, ",");
            for(int i = 0; i < 4; i++){
                switch (i)
                {
                case 0:
                    strcpy(infoAux.nome, campo);
                    
                    break;
                case 1:
                    
                    infoAux.matricula = atoi(campo);
                    break;
                case 2:
                    infoAux.ranking = atoi(campo);
                    
                    break;
                case 3:
                    strcpy(infoAux.curso, campo);
                    break;    
                
                default:
                    break;
                }
                
                campo = strtok(NULL, ",");
            }
            insereHeap(heap, infoAux);
        }
    fclose(f);
}

int conta_linha(){
    FILE *f = fopen("dataset_v1.csv", "r");
    int n = 0;
    char ch;
    if(!f){
        printf("Arquivo não encontrado.\n");
        return 0;
    }
    while(!feof(f)){
        ch = fgetc(f);
        if(ch == '\n'){
            n++;
        }
    }
    fclose(f);
    return n;
}

void uhhh(){
    Heap *base = criaHeap(9000);
    int max_linha = conta_linha();
    srand(time(0));
    for(int i = 0; i < 500; i++){
        int rando = rand() % max_linha + 1;
        insereHeapCSV(base, rando);
       
    }
    
}



