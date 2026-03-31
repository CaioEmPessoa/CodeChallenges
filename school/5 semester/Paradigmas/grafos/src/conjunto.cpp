#include "../include/conjunto.hpp"

// -------------------------------------------------------
// TODO 2.1 — crescer
// -------------------------------------------------------
void Conjunto::crescer() {
    // 1. cap *= 2
    // 2. int* novo = new int[cap]
    // 3. Copiar cada elemento
    // 4. delete[] elementos
    // 5. elementos = novo
}

// -------------------------------------------------------
// Construtor
// -------------------------------------------------------
Conjunto::Conjunto(int capInicial)
    : tam(0), cap(capInicial), elementos(new int[capInicial]) {}

// -------------------------------------------------------
// TODO 2.2 — Destrutor
// -------------------------------------------------------
Conjunto::~Conjunto() {
    // delete[] elementos
}

// -------------------------------------------------------
// TODO 2.3 — Construtor de cópia
// -------------------------------------------------------
Conjunto::Conjunto(const Conjunto& outro)
    : tam(outro.tam), cap(outro.cap),
      elementos(new int[outro.cap]) {
    // Copiar cada elemento de outro.elementos para elementos
}

// -------------------------------------------------------
// Sobrecarga 1 — Atribuição
// -------------------------------------------------------
Conjunto& Conjunto::operator=(const Conjunto& outro) {
    // TODO 2.4:
    // Guard: if (this == &outro) return *this
    // delete[] elementos
    // Copiar tam, cap; alocar new int[cap]; copiar elementos
    // return *this
}

// -------------------------------------------------------
// TODO 2.5 — pertence
// -------------------------------------------------------
bool Conjunto::pertence(int x) const {
    // Percorrer elementos[0..tam-1]
    // Retornar true se algum for igual a x
}

// -------------------------------------------------------
// TODO 2.6 — adicionar
// -------------------------------------------------------
void Conjunto::adicionar(int x) {
    // if (pertence(x)) return
    // if (tam == cap) crescer()
    // elementos[tam++] = x
}

// -------------------------------------------------------
// TODO 2.7 — remover
// -------------------------------------------------------
void Conjunto::remover(int x) {
    // Encontrar índice i onde elementos[i] == x
    // elementos[i] = elementos[tam-1]; tam--
    // Se não encontrar, retornar sem fazer nada
}

// -------------------------------------------------------
// TODO 2.8 — tamanho
// -------------------------------------------------------
int Conjunto::tamanho() const {
    // return tam
}

// -------------------------------------------------------
// Sobrecarga 2 — Cardinalidade  ~A
// -------------------------------------------------------
int Conjunto::operator~() const {
    // TODO 2.9: return tam
}

// -------------------------------------------------------
// Sobrecarga 3 — Pertinência  A << x
// -------------------------------------------------------
bool Conjunto::operator<<(int x) const {
    // TODO 2.10: return pertence(x)
}

// -------------------------------------------------------
// Sobrecarga 4 — Inserção  A += x
// -------------------------------------------------------
Conjunto& Conjunto::operator+=(int x) {
    // TODO 2.11: adicionar(x); return *this
}

// -------------------------------------------------------
// Sobrecarga 5 — Igualdade  A == B
// -------------------------------------------------------
bool Conjunto::operator==(const Conjunto& outro) const {
    // TODO 2.12:
    // Se tam != outro.tam: return false
    // Para cada elemento de *this:
    //   Se !outro.pertence(elem): return false
    // return true
}

bool Conjunto::operator!=(const Conjunto& outro) const {
    return !(*this == outro);
}

// -------------------------------------------------------
// Sobrecarga 6 — Subconjunto  A <= B
// -------------------------------------------------------
bool Conjunto::operator<=(const Conjunto& outro) const {
    // TODO 2.13:
    // Para cada elemento de *this:
    //   Se !outro.pertence(elem): return false
    // return true
}

// -------------------------------------------------------
// Sobrecarga 7 — União  A | B
// -------------------------------------------------------
Conjunto Conjunto::operator|(const Conjunto& outro) const {
    // TODO 2.14:
    // Conjunto resultado
    // Adicionar todos os elementos de *this
    // Para cada elemento de outro: se não pertence, adicionar
    // return resultado
}

// -------------------------------------------------------
// Sobrecarga 8 — Interseção  A & B
// -------------------------------------------------------
Conjunto Conjunto::operator&(const Conjunto& outro) const {
    // TODO 2.15:
    // Conjunto resultado
    // Para cada elemento de *this:
    //   Se outro.pertence(elem): resultado.adicionar(elem)
    // return resultado
}

// -------------------------------------------------------
// Sobrecarga 9 — Diferença  A - B
// -------------------------------------------------------
Conjunto Conjunto::operator-(const Conjunto& outro) const {
    // TODO 2.16:
    // Conjunto resultado
    // Para cada elemento de *this:
    //   Se !outro.pertence(elem): resultado.adicionar(elem)
    // return resultado
}

// -------------------------------------------------------
// Impressão
// -------------------------------------------------------
std::ostream& Conjunto::imprimir(std::ostream& os) const {
    // TODO 2.17:
    // Formato: { 1, 3, 5, 7 }
    // Se vazio: { }
    // Não colocar vírgula após o último elemento
}

// Função livre — operador de saída
std::ostream& operator<<(std::ostream& os, const Conjunto& c) {
    return c.imprimir(os);
}