/**
 * @file string_utils.c
 * @brief Exercícios acerca de funções de análise e manipulação de strings em C
 *
 * Conjunto de funções simples e progressivas para aprendizado de manipulação de strings,
 * ponteiros, iteração em arrays de char, passagem por valor/referência e tratamento de casos borda.
 */

#include <string.h>  /* funções strlen() e strcpy() são permitidas */
#include <stdio.h>

/* ========================================================================= */
/* Funções de contagem e verificação                                        */
/* ========================================================================= */


/**
 * @brief Conta quantas vezes um determinado caractere aparece na string
 * @param str Ponteiro para a string terminada em '\0'
 * @param c Caractere a ser procurado
 * @return Número de ocorrências do caractere
 */
int contar_ocorrencias(const char *str, char c);

/**
 * @brief Remove espaços extras: deixa apenas um espaço entre palavras,
 * remove espaços no início e no final da string
 * @param str String a ser normalizada (deve ser modificável)
 */
void remover_espacos_extras(char *str);

/**
 * @brief Substitui todas as ocorrências de um caractere por outro
 * @param str String a ser modificada
 * @param antigo Caractere a ser substituído
 * @param novo Novo caractere
 */
void substituir_caractere(char *str, char antigo, char novo){
    size_t str_size = strlen(str);

    for (int i = 0; i < str_size; i++) {
        if(str[i] == antigo) {
            str[i] = novo;
        }
    }
};

/**
 * @brief Verifica se duas strings são anagramas uma da outra
 * @note Ignora maiúsculas/minúsculas e considera apenas letras
 * @param a Primeira string
 * @param b Segunda string
 * @return 1 se forem anagramas, 0 caso contrário
 */

int eh_anagrama(const char *a, const char *b) {
    char alp [26*2] = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    int  vls1[26] = {};
    int  vls2[26] = {};
    int plc = 0;

    size_t a_len = strlen(a);
    size_t b_len = strlen(b);

    for (int i = 0; i < a_len; i++) {
        for (int j = 0; j < 26*2; j++) {
            if (alp[j] == a[i]) {
                plc = j;
                if(j >= 26) plc = j-26;

                vls1[plc]++;
            }
        }
    }

    for (int i = 0; i < b_len; i++) {
        for (int j = 0; j < 26*2; j++) {
            if (alp[j] == b[i]) {
                plc = j;
                if(j >= 26) plc = j-26;

                vls2[plc]++;
            }
        }
    }

    int equal = 1;
    for (int i=0; i<26; i++ ) {
        if (vls1[i]!=vls2[i]) equal = 0;
    }

    return equal;

};

/**
 * @brief Capitaliza a primeira letra de cada palavra
 * @note Considera palavras separadas por espaços
 * @param str String a ser modificada (deve ser modificável)
 * @example "ola mundo" → "Ola Mundo"
 */
void capitalizar_palavras(char *str);

int main() {
    char str[] = "Testando com uma Longa e Linda Frase";
    char ant = 'a';
    char new = 'p';

    // printf("%s\n", str);
    substituir_caractere(str, ant, new);
    // printf("%s\n", str);

    char str_a[] = "ab cDEFghIJ";
    char str_b[] = "abcd  IJHgfe";
    int result = 0;

    printf("%s - %s\n", str_a, str_b);
    result = eh_anagrama(str_a, str_b);
    printf("\nResult: %d\n", result);

    return 0;
}