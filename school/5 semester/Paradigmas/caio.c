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


int contar_substring(const char *texto, const char *busca) {
    int tamTexto = strlen(texto), tamBusca = strlen(busca);
    int qnt = 0, count = 0;

    for (int i = 0; i < tamTexto; i++) {

        for (int j = 0; j < tamBusca; j++) {
            if (texto[i+j] == busca[j]) count++;
        }

        if (count == tamBusca) qnt++;
        count = 0;
    }

    return qnt;
}

/**
 * @brief Conta quantas vezes um determinado caractere aparece na string
 * @param str Ponteiro para a string terminada em '\0'
 * @param c Caractere a ser procurado
 * @return Número de ocorrências do caractere
 */
int contar_ocorrencias(const char *str, const char c) {
    int oc = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) oc++;
    }

    return oc;
};

/**
 * @brief Remove espaços extras: deixa apenas um espaço entre palavras,
 * remove espaços no início e no final da string
 * @param str String a ser normalizada (deve ser modificável)
 */
void remover_espacos_extras(char *str) {
    size_t start = 0, size = strlen(str), end = size + 1;

    // Confere ate quando tem espaços no começo da string
    while (str[start] == ' ') {
        start++;
    }

    // Confere ate quando tem espaços no fim da string
    while (str[end-1] == ' ') {
        end--;
    }

    // Nova lista pra armazenar o resultado, com o novo tamanho.
    char result[end - start];
    size_t count = 0;

    // Armazena apeans os itens a partir de quando não tem mais espaços,
    // até quando se tem somente caracteres.
    for (size_t i = start; i < end-1; i++) {
        result[count++] = str[i];
    }

    // Copia o valor do resultado na string passada como parametro.
    strcpy(str, result);
};

/**
 * @brief Substitui todas as ocorrências de um caractere por outro
 * @param str String a ser modificada
 * @param antigo Caractere a ser substituído
 * @param novo Novo caractere
 */
void substituir_caractere(char *str, char antigo, char novo){

    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i] == antigo) str[i] = novo;
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
    int  values[26] = {}; // Array contadora, com o tamanho do alfabeto.

    for (size_t i = 0; a[i] != '\0'; i++) {
        char c = a[i];
        // Adiciona +1 na respectiva posicao da letra na lista de valores.
        // Letras maiusculas adicionam na mesma posicao das minusculas
        if (c >= 'a' && c <= 'z') values[c - 'a']++;
        else if (c >= 'A' && c <= 'Z') values[c - 'A']++;
    }

    // Mesma coisa que o loop acima, porém ao inves de adicionar +1,
    // remove -1 item na posicao da letra na lista do alfabeto.
    for (size_t i = 0; b[i] != '\0'; i++) {
        char c = b[i];
        if (c >= 'a' && c <= 'z') values[c - 'a']--;
        else if (c >= 'A' && c <= 'Z') values[c - 'A']--;
    }

    // Caso todos itens nao forem == 0, nao é um anagrama.
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
void capitalizar_palavras(char *str) {
    int diff = 'a'-'A'; // Pegando a diferença entre os chars na tabela ascii

    // apenas no caso do primeiro char
    if (str[0] >= 'a' && str[0] <= 'z') str[0] -= diff;

    for (int i = 0; str[i] != '\0'; i++) {
        // Caso o caractere atual seja um espaço e
        // o caractere seguinte uma letra minuscula
        if (str[i]   == ' ' &&
            str[i+1] >= 'a' && str[i+1] <= 'z'
        ) {
            str[i+1] -= diff; // converte pra upper com base na diff
        }
    }

};

int main() {

    /*
        TESTE FUNCAO CONTAR_SUBSTRING
    */

    char str_sub_a[] = "po tdoi pbem";
    char str_sub_b[] = "o";
    int result_sub   = 0;

    printf("Texto: %s - Busca: %s\n", str_sub_a, str_sub_b);
    result_sub = contar_substring(str_sub_a, str_sub_b);
    printf("Qntd: %d\n", result_sub);


    /*
        TESTE FUNCAO SUBSTITUIR CARACTERE.
    */
    char str_sub[] = "Testando com uma Longa e Linda Frase";
    char ant = 'a';
    char new = 'p';

    // printf("%s\n", str_sub);
    substituir_caractere(str_sub, ant, new);
    // printf("%s\n", str_sub);

    /*
        TESTE FUNCAO EH_ANAGRAMA
    */
    char str_an_a[] = "Teste A";
    char str_an_b[] = "eTSet a";
    int result_an = 0;

    // printf("%s - %s\n", str_an_a, str_an_b);
    result_an = eh_anagrama(str_an_a, str_an_b);
    // printf("\nResult: %d\n", result_an);

    /*
        TESTE FUNCAO REMOVER_ESPACOS_EXTRAS
    */
    char str_spc[] = "   Espaços Nao importantes      ";
    // printf("%s\n", str_spc);
    remover_espacos_extras(str_spc);
    // printf("%s\n", str_spc);


    /*
        TESTE FUNCAO CONTAR_OCORRENCIAS
    */
    printf("\n----- funcao contar_ocorrencias -----\n");
    char str_oc[] = "01 Contar ocorrencias De UMA STRING 12";
    char char_oc  = '1';
    int result_oc;

    printf("Parametro: %s - %c\n", str_oc, char_oc);
    result_oc = contar_ocorrencias(str_oc, char_oc);
    printf("Resposta : Encontradas %d ocorrencias do caractere '%c'\n", result_oc, char_oc);

    /*
        TESTE FUNCAO REMOVER_ESPACOS_EXTRAS
    */
    printf("\n----- funcao remover_espacos_extras -----\n");
    char str_spc[] = "   Espaços Nao importantes      ";
    printf("Parametro: %s\n", str_spc);
    remover_espacos_extras(str_spc);
    printf("Resposta : %s\n", str_spc);

    /*
        TESTE FUNCAO SUBSTITUIR CARACTERE.
    */
    printf("\n----- funcao substituir_caractere -----\n");
    char str_sub[] = "Testando com uma Longa e Linda Frase";
    char ant = 'a';
    char new = 'p';

    printf("Parametro: %s\n", str_sub);
    substituir_caractere(str_sub, ant, new);
    printf("Resposta : %s\n", str_sub);

    /*
        TESTE FUNCAO EH_ANAGRAMA
    */
    printf("\n----- funcao eh_anagrama -----\n");
    char str_an_a[] = "Teste A";
    char str_an_b[] = "eTSet a";
    int result_an = 0;

    printf("Parametro: %s - %s\n", str_an_a, str_an_b);
    result_an = eh_anagrama(str_an_a, str_an_b);
    printf("\nResposta : %d\n", result_an);

    /*
        TESTE FUNCAO CAPITALIZAR_PALAVRAS
    */
    printf("\n----- funcao capitalizar_palavras -----\n");
    char str_cap[] = "a Don pedro  segundo";

    printf("Parametro: %s\n", str_cap);
    capitalizar_palavras(str_cap);
    printf("Resposta : %s\n", str_cap);


    printf("\n\n\n");

    return 0;
}