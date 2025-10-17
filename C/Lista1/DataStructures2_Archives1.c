#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[30], conceito, linha[200];
    int matricula, faltas;
    float nota1, nota2, nota3, media;
    FILE *arq, *arq2;

    if((arq = fopen("alunos.txt", "r")) == NULL){
        printf("Erro ao abrir arquivo.\n"); return 0;
    }
    if((arq2 = fopen("conceitos.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n"); return 0;
    }
    while(fgets(linha, sizeof(linha), arq)){
        if (sscanf(linha, "%d %[^0-9\n] %f %f %f %d", &matricula, nome, &nota1, &nota2, &nota3, &faltas) == 6){
            media = (nota1 + nota2 + nota3)/3;
            
            if(faltas > 18) conceito = 'F';
            else if(media < 6.0) conceito = 'R';
            else if(media >= 6.0 && media < 7.5) conceito = 'C';
            else if(media >= 7.5 && media < 9.0) conceito = 'B';
            else if(media >= 9.0 && media <= 10.0) conceito = 'A';

            fprintf(arq2, "%04d %-30s %5c\n", matricula, nome, conceito);
        }
    }
    fclose(arq);
    fclose(arq2);
    return 0;
}