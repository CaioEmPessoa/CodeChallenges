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
    size_t start = 0, size = strlen(str), end = size;

    // Confere ate quando tem espaços no começo da string
    while (start < size && str[start] == ' ') {
        start++;
    }

    // Confere ate quando tem espaços no fim da string
    while (end > start && str[end-1] == ' ') {
        end--;
    }

    if (start >= end) str[0] = '\0'; return;

    // Nova lista pra armazenar o resultado, com o novo tamanho.
    char result[end - start];
    size_t count = 0;

    // Armazena apeans os itens a partir de quando não tem mais espaços,
    // até quando se tem somente caracteres.
    for (size_t i = start; i < end; i++) {
        result[count++] = str[i];
    }

    result[count] = '\0';

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

    // Array de testes para contar_ocorrencias
    struct {
        char str[50];
        char caractere;
        int esperado;
    } testes_oc[] = {
        {"banana", 'a', 3},
        {"banana", 'b', 1},
        {"banana", 'x', 0},
        {"", 'a', 0},
        {"aaaaa", 'a', 5},
        {"Casa", 'a', 2},
        {"Hello", 'l', 2},
        {"123123", '1', 2},
        {"test", 't', 2},
        {"ABC", 'a', 0}
    };

    for(int i = 0; i < 10; i++) {
        printf("\nTeste %d:\n", i+1);
        printf("Parametro: \"%s\" - '%c'\n", testes_oc[i].str, testes_oc[i].caractere);
        int result_oc = contar_ocorrencias(testes_oc[i].str, testes_oc[i].caractere);
        printf("Resposta : %d ocorrencias\n", result_oc);
        printf("Esperado : %d ocorrencias\n", testes_oc[i].esperado);
    }

    /*
        TESTE FUNCAO REMOVER_ESPACOS_EXTRAS
    */
    printf("\n----- funcao remover_espacos_extras -----\n");

    // Array de testes para remover_espacos_extras
    struct {
        char str[50];
        char esperado[50];
    } testes_spc[] = {
        {" ola mundo ", "ola mundo"},
        {"ola mundo", "ola mundo"},
        {"ola mundo", "ola mundo"},
        {" teste", "teste"},
        {"teste ", "teste"},
        {"a b c", "a b c"},
        {"", ""},
        {" ", ""},
        {"java c", "java c"},
        {"a b", "a b"}
    };

    for(int i = 0; i < 10; i++) {
        // Criar uma cópia da string para não modificar o original
        char str_spc[100];
        strcpy(str_spc, testes_spc[i].str);

        printf("\nTeste %d:\n", i+1);
        printf("Parametro: \"%s\"\n", str_spc);
        remover_espacos_extras(str_spc);
        printf("Resposta : \"%s\"\n", str_spc);
        printf("Esperado : \"%s\"\n", testes_spc[i].esperado);
    }

    /*
        TESTE FUNCAO SUBSTITUIR CARACTERE
    */
    printf("\n----- funcao substituir_caractere -----\n");

    // Array de testes para substituir_caractere
    struct {
        char str[50];
        char antigo;
        char novo;
        char esperado[50];
    } testes_sub[] = {
        {"banana", 'a', 'o', "bonono"},
        {"teste", 'e', 'i', "tisti"},
        {"abc", 'x', 'y', "abc"},
        {"aaaa", 'a', 'b', "bbbb"},
        {"hello", 'l', 'x', "hexxo"},
        {"", 'a', 'b', ""},
        {"1231", '1', '9', "9239"},
        {"casa", 'a', 'e', "cese"},
        {"java", 'j', 'J', "Java"},
        {"abc", 'c', 'd', "abd"}
    };

    for(int i = 0; i < 10; i++) {
        char str_sub[50];
        strcpy(str_sub, testes_sub[i].str);

        printf("\nTeste %d:\n", i+1);
        printf("Parametro: \"%s\" (antigo: '%c', novo: '%c')\n",
               str_sub, testes_sub[i].antigo, testes_sub[i].novo);
        substituir_caractere(str_sub, testes_sub[i].antigo, testes_sub[i].novo);
        printf("Resposta : \"%s\"\n", str_sub);
        printf("Esperado : \"%s\"\n", testes_sub[i].esperado);
    }

    /*
        TESTE FUNCAO EH_ANAGRAMA
    */
    printf("\n----- funcao eh_anagrama -----\n");

    // Array de testes para eh_anagrama
    struct {
        char str1[50];
        char str2[50];
        int esperado;
    } testes_an[] = {
        {"amor", "roma", 1},
        {"listen", "silent", 1},
        {"abc", "cab", 1},
        {"abc", "abcd", 0},
        {"hello", "world", 0},
        {"roma", "amor", 1},
        {"teste", "sete", 0},
        {"anagrama", "amaragan", 1},
        {"abc", "def", 0},
        {"rat", "tar", 1}
    };

    for(int i = 0; i < 10; i++) {
        printf("\nTeste %d:\n", i+1);
        printf("Parametro: \"%s\" - \"%s\"\n", testes_an[i].str1, testes_an[i].str2);
        int result_an = eh_anagrama(testes_an[i].str1, testes_an[i].str2);
        printf("Resposta : %d\n", result_an);
        printf("Esperado : %d\n", testes_an[i].esperado);
    }

    /*
        TESTE FUNCAO CAPITALIZAR_PALAVRAS
    */
    printf("\n----- funcao capitalizar_palavras -----\n");

    // Array de testes para capitalizar_palavras
    struct {
        char str[50];
        char esperado[50];
    } testes_cap[] = {
        {"ola mundo", "Ola Mundo"},
        {"java programming", "Java Programming"},
        {"hello world", "Hello World"},
        {"a b c", "A B C"},
        {"teste", "Teste"},
        {"programacao em c", "Programacao Em C"},
        {"", ""},
        {"abc def ghi", "Abc Def Ghi"},
        {"open ai", "Open Ai"},
        {"estrutura de dados", "Estrutura De Dados"}
    };

    for(int i = 0; i < 10; i++) {
        char str_cap[100];
        strcpy(str_cap, testes_cap[i].str);

        printf("\nTeste %d:\n", i+1);
        printf("Parametro: \"%s\"\n", str_cap);
        capitalizar_palavras(str_cap);
        printf("Resposta : \"%s\"\n", str_cap);
        printf("Esperado : \"%s\"\n", testes_cap[i].esperado);
    }

    printf("\n\n\n");
    return 0;
}