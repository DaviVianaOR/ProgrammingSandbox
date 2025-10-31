#include <stdio.h>
#include <string.h>

typedef struct {
    char titulo[31];
    int chave;
    float preco;
} tipoitem;

int main(void) {
    tipoitem livros[] = {
        {"O Senhor dos Aneis", 10, 59.90},
        {"Dom Casmurro", 20, 39.50},
        {"1984", 30, 45.00},
        {"A Revolucao dos Bichos", 40, 29.90},
        {"O Hobbit", 50, 49.90},
        {"Memorias Postumas", 60, 42.00},
        {"Crime e Castigo", 70, 58.00},
        {"O Pequeno Principe", 80, 25.00},
        {"A Divina Comedia", 90, 65.00},
        {"Neuromancer", 100, 55.00}
    };

    FILE *arq = fopen("livros.bin", "wb");
    if (!arq) {
        perror("Erro ao criar livros.bin");
        return 1;
    }

    fwrite(livros, sizeof(tipoitem), 10, arq);
    fclose(arq);

    printf("✅ Arquivo 'livros.bin' criado com sucesso!\n");
    return 0;
}
