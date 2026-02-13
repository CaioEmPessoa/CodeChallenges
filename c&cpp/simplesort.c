#include <stdio.h>

int main()
{
    char nome[] = "abcdiefghjklmnopqrstuvwxyz";

    size_t tam_nome = sizeof(nome) / sizeof(nome[0]);

    char nome_ord[tam_nome];

    char  tmp = ' ';

    printf("Original: %s\n", nome);
    printf("%s\n", nome_ord);

    for (int i = 0; i < tam_nome; i++) {
        for (int j = 0; j < tam_nome; j++) {
            if(nome[i] > nome[j]) {
                tmp = nome[i];
                nome[i] = nome[j];
                nome[j] = tmp;
            }
            nome_ord[i] = nome[i];
        }
    }

    printf("%s\n", nome_ord);
    printf("Ordenado: %s\n", nome);

    return 0;
}