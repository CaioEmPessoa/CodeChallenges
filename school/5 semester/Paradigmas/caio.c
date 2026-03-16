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
    int  values[26] = {};

    size_t a_len = strlen(a);
    size_t b_len = strlen(b);

    for (size_t i = 0; i < a_len; i++) {
        char c = a[i];
        if (c >= 'a' && c <= 'z') values[c - 'a']++;
        else if (c >= 'A' && c <= 'Z') values[c - 'A']++;
    }

    for (size_t i = 0; i < b_len; i++) {
        char c = b[i];
        if (c >= 'a' && c <= 'z') values[c - 'a']--;
        else if (c >= 'A' && c <= 'Z') values[c - 'A']--;
    }

    for (int i=0; i<26; i++ ) {
        if (values[i] != 0) return 0;
    }

    return 1;

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

    char str_a[] = "Teste A";
    char str_b[] = "eTSet a";
    int result = 0;

    printf("%s - %s\n", str_a, str_b);
    result = eh_anagrama(str_a, str_b);
    printf("\nResult: %d\n", result);

    return 0;
}