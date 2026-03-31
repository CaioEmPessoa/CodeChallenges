#ifndef CONJUNTO_HPP
#define CONJUNTO_HPP

#include <iostream>
#include <stdexcept>

class Conjunto {
protected:
    int* elementos;  // array de inteiros alocado manualmente
    int  tam;        // quantidade de elementos presentes
    int  cap;        // capacidade alocada

    // TODO 2.1 — crescer
    // Dobra a capacidade do array interno quando ele está cheio
    // 1. cap *= 2
    // 2. int* novo = new int[cap]
    // 3. Copiar cada elemento: novo[i] = elementos[i]
    // 4. delete[] elementos
    // 5. elementos = novo
    void crescer();

public:

    // Construtor
    Conjunto(int capInicial = 16);

    // TODO 2.2 — Destrutor
    // delete[] elementos
    ~Conjunto();

    // TODO 2.3 — Construtor de cópia (deep copy)
    // Necessário para evitar que dois objetos compartilhem
    // o mesmo ponteiro e causem double free
    Conjunto(const Conjunto& outro);

    // Sobrecarga 1 — Atribuição  A = B
    // Guard: if (this == &outro) return *this
    // delete[] elementos; copiar tam e cap; alocar; copiar elementos
    Conjunto& operator=(const Conjunto& outro);

    // TODO 2.5 — pertence
    // Percorre elementos[0..tam-1]
    // Retorna true se algum for igual a x
    bool pertence(int x) const;

    // TODO 2.6 — adicionar
    // Insere x somente se ainda não pertence
    // Cresce o array se necessário
    void adicionar(int x);

    // TODO 2.7 — remover
    // Remove x sem deixar buraco no array
    // Substitui pelo último: elementos[i] = elementos[tam-1]; tam--
    void remover(int x);

    // TODO 2.8 — tamanho
    // Retorna tam
    int tamanho() const;

    // Sobrecarga 2 — Cardinalidade  ~A
    // Retorna o número de elementos
    // Uso: int n = ~A;
    int operator~() const;

    // Sobrecarga 3 — Pertinência  A << x
    // Retorna true se x pertence a A
    // Uso: if (A << 5) { ... }
    bool operator<<(int x) const;

    // Sobrecarga 4 — Inserção  A += x
    // Adiciona x e retorna *this
    // Uso: A += 1 += 2 += 3;
    Conjunto& operator+=(int x);

    // Sobrecarga 5 — Igualdade  A == B
    // Dois conjuntos são iguais se têm os mesmos elementos
    bool operator==(const Conjunto& outro) const;

    // Reutiliza operator==
    bool operator!=(const Conjunto& outro) const;

    // Sobrecarga 6 — Subconjunto  A <= B
    // Retorna true se todo elemento de A também pertence a B
    bool operator<=(const Conjunto& outro) const;

    // Sobrecarga 7 — União  A | B
    // Retorna novo Conjunto com todos os elementos de A e de B
    Conjunto operator|(const Conjunto& outro) const;

    // Sobrecarga 8 — Interseção  A & B
    // Retorna novo Conjunto com elementos comuns a A e B
    Conjunto operator&(const Conjunto& outro) const;

    // Sobrecarga 9 — Diferença  A - B
    // Retorna elementos que estão em A mas não em B
    Conjunto operator-(const Conjunto& outro) const;

    // Método de impressão — chamado pelo operator<< externo
    // Formato: { 1, 3, 5, 7 }   Se vazio: { }
    std::ostream& imprimir(std::ostream& os) const;
};

// Operador de saída como função livre
// (evita o uso de friend; chama o método público imprimir)
std::ostream& operator<<(std::ostream& os, const Conjunto& c);

#endif // CONJUNTO_HPP