#include <stdio.h>
#define ITENSPAGINA 4
#define MAXTABELA 100

typedef struct {
    int posicao;
    int chave;
} tipoindice;

typedef struct{
    char titulo[31]; int chave; float preco;
} tipoitem;

int pesquisa (tipoindice tab[], int tam, tipoitem* item, FILE *arq){
    tipoitem pagina[ITENSPAGINA];
    int i, quantitens;
    long int desloc;

    i = 0;
    while( i < tam && tab[i].chave <= item->chave) i++;

    if (i==0) return 0;

    else{
        fseek(arq, 0, SEEK_END);
        long int total = ftell(arq) / sizeof(tipoitem);
        int totalPaginas = (total + ITENSPAGINA - 1) / ITENSPAGINA;
        quantitens = (tab[i-1].posicao == totalPaginas) ? total % ITENSPAGINA : ITENSPAGINA;
    }

    desloc = (tab[i-1].posicao-1)*ITENSPAGINA*sizeof(tipoitem);
    fseek(arq, desloc, SEEK_SET);
    fread(&pagina, sizeof(tipoitem), quantitens, arq);

    for (i = 0; i < quantitens; i++){
        if(pagina[i].chave == item->chave){
            *item = pagina[i];
            return 1;
        }
    }
    return 0;
}
int main() {
    tipoindice tabela[MAXTABELA];
    FILE *arq; tipoitem x; int pos, cont;

    if((arq = fopen("livros.bin", "rb")) == NULL){
        printf("Erro na abertura do arquivo.\n"); return 0;
    }

    cont = 0; pos = 0;
    while(fread(&x, sizeof(x), 1, arq) == 1){
        cont++;
        if(cont%ITENSPAGINA == 1){
            tabela[pos].chave = x.chave;
            tabela[pos].posicao = pos+1;
            pos++;
        }
    }
    fflush(stdout);
    printf("Insira o código do livro-alvo: "); scanf("%d", &x.chave);

    if(pesquisa(tabela, pos, &x, arq)) printf("Livro %s (cod.: %d) foi localizado", x.titulo, x.chave);
    else printf("Livro de cod. %d nao localizado.", x.chave);

    fclose(arq);
    return 0; 
}