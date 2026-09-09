#include <stdio.h>
#include <string.h>

int main()
{
    char nome[100][100] = {
        "abcdiefghjklmnopqrstuvwxyz",
        "caio polonio",
        "meu nome é fábio na verdade eu venho mentindo todos esses anos",
        "zeiipow"
    };

    size_t tam_nome = sizeof(nome) / sizeof(nome[0]);

    char  tmp[100];

    printf("Originais\n");
    for (int i = 0; i < 4; i++) {
        printf("%i - %s\n", i, nome[i]);
    }
    printf("\n");

    for (int i = 0; i < tam_nome; i++) {
        for (int j = 0; j < tam_nome; j++) {
            if(nome[i][0] > nome[j][0]) {
                memcpy(tmp, nome[i], 100);
                memcpy(nome[i], nome[j], 100);
                memcpy(nome[j], tmp, 100);
            }
        }
    }

    printf("Ordenados (de tras pra frente)\n");
    for (int i = 0; i < 4; i++) {
        printf("%i - %s\n", i, nome[i]);
    }
    printf("\n");

    char first_nome[100];
    memcpy(first_nome, nome, 100);
    size_t tam_first_nome = sizeof(first_nome) / sizeof(first_nome[0]);
    char tmp_first[100];
    
    printf("Primeira string (original) %s\n", first_nome);
    for (int i = 0; i < tam_first_nome; i++) {
        for (int j = 0; j < tam_first_nome; j++) {
            if(first_nome[i] > first_nome[j]) {
                tmp_first = first_nome[i];
                first_nome[i] = first_nome[j];
                first_nome[j] = tmp_first;
            }
        }
    }
    printf("Primeira string (ordenada) %s\n", first_nome);

    return 0;
}