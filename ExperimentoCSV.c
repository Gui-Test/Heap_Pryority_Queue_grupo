#include "arq_publico.h"

int insereHeapCSV(Heap *heap, int nlinha){
    FILE *f = fopen("dataset_v1.csv", "r");
    info infoAux;
    int numIt = 0;
    if(!f){
        printf("Arquivo não encontrado 2.\n");
        return 0;
    }
   
    char linha[1024];
    fgets(linha, 1024, f);
    for(int i = 0;i < nlinha;i++) {
        fgets(linha, 1024, f);    
    }
    if(!feof(f)){
        //printf("Linha %i lida: %s", nlinha, linha);
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
        numIt = insereHeap(heap, infoAux);
    }
    fclose(f);
    return numIt;
    
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

void experimento(DadosCSV dados[]){
    float numIt = 0;
    int tamanho = 9000;
    int iDados = 0;
    float mult500 = 500;
    Heap *base = criaHeap(tamanho);
    
    int max_linha = conta_linha();
    srand(time(0));
    for(int i = 0; i < tamanho; i++){
        int rando = rand() % max_linha + 1;
        numIt = numIt + insereHeapCSV(base, rando);
        
        if(i == mult500 - 1){
            dados[iDados].iterações = numIt / mult500;
            dados[iDados].numDados = i + 1;
            mult500 = mult500 + 500;
            iDados++;
        }      
    }
    //Função para mostrar os dados do experimento
    /*for(int i = 0; i < 18;i++){
        printf("%i ",i);
        float it = dados[i].iterações;
        int numDados = dados[i].numDados;

        printf("%f,%i\n ", it,numDados);
        
    }*/
    
}


void insereNoCSV(DadosCSV dados[],int tam){
    FILE *f = fopen("dados.csv", "w");
    info infoAux;
    if(!f){
        printf("Arquivo não encontrado.\n");
        return;
    }
    int i = 0;
    float it;
    int numDados;
    fprintf(f,"Iterações,NumeroInserido\n");
    for(int i = 0; i < tam;i++){
        //printf("%i ",i);
        it = dados[i].iterações;
        numDados = dados[i].numDados;

        fprintf(f,"%f,%i\n", it,numDados);
        
    }
    fclose(f);
}



