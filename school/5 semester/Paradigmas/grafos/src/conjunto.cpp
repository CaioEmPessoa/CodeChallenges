#include "../include/conjunto.hpp"

// -------------------------------------------------------
// TODO 2.1 — crescer
// -------------------------------------------------------
void Conjunto::crescer() {
    cap *= 2;
    int* novo = new int[cap];
    for (int i = 0; i < tam; ++i) {
        novo[i] = elementos[i];
    }
    delete[] elementos;
    elementos = novo;
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
    delete[] elementos;
}

// -------------------------------------------------------
// TODO 2.3 — Construtor de cópia
// -------------------------------------------------------
Conjunto::Conjunto(const Conjunto& outro)
    : tam(outro.tam), cap(outro.cap),
      elementos(new int[outro.cap]) {
    for (int i = 0; i < tam; ++i) {
        elementos[i] = outro.elementos[i];
    }
}

// -------------------------------------------------------
// Sobrecarga 1 — Atribuição
// -------------------------------------------------------
Conjunto& Conjunto::operator=(const Conjunto& outro) {
    if (this == &outro) {
        return *this;
    }
    delete[] elementos;
    tam = outro.tam;
    cap = outro.cap;
    elementos = new int[cap];
    for (int i = 0; i < tam; ++i) {
        elementos[i] = outro.elementos[i];
    }
    return *this;
}

// -------------------------------------------------------
// TODO 2.5 — pertence
// -------------------------------------------------------
bool Conjunto::pertence(int x) const {
    for (int i = 0; i < tam; ++i) {
        if (elementos[i] == x) {
            return true;
        }
    }
    return false;
}

// -------------------------------------------------------
// TODO 2.6 — adicionar
// -------------------------------------------------------
void Conjunto::adicionar(int x) {
    if (pertence(x)) {
        return;
    }
    if (tam == cap) {
        crescer();
    }
    elementos[tam++] = x;
}

// -------------------------------------------------------
// TODO 2.7 — remover
// -------------------------------------------------------
void Conjunto::remover(int x) {
    for (int i = 0; i < tam; ++i) {
        if (elementos[i] == x) {
            elementos[i] = elementos[tam - 1];
            tam--;
            return;
        }
    }
}

// -------------------------------------------------------
// TODO 2.8 — tamanho
// -------------------------------------------------------
int Conjunto::tamanho() const {
    return tam;
}

// -------------------------------------------------------
// Sobrecarga 2 — Cardinalidade  ~A
// -------------------------------------------------------
int Conjunto::operator~() const {
    return tam;
}

// -------------------------------------------------------
// Sobrecarga 3 — Pertinência  A << x
// -------------------------------------------------------
bool Conjunto::operator<<(int x) const {
    return pertence(x);
}

// -------------------------------------------------------
// Sobrecarga 4 — Inserção  A += x
// -------------------------------------------------------
Conjunto& Conjunto::operator+=(int x) {
    adicionar(x);
    return *this;
}

// -------------------------------------------------------
// Sobrecarga 5 — Igualdade  A == B
// -------------------------------------------------------
bool Conjunto::operator==(const Conjunto& outro) const {
    if (tam != outro.tam) {
        return false;
    }
    for (int i = 0; i < tam; ++i) {
        if (!outro.pertence(elementos[i])) {
            return false;
        }
    }
    return true;
}

bool Conjunto::operator!=(const Conjunto& outro) const {
    return !(*this == outro);
}

// -------------------------------------------------------
// Sobrecarga 6 — Subconjunto  A <= B
// -------------------------------------------------------
bool Conjunto::operator<=(const Conjunto& outro) const {
    for (int i = 0; i < tam; ++i) {
        if (!outro.pertence(elementos[i])) {
            return false;
        }
    }
    return true;
}

// -------------------------------------------------------
// Sobrecarga 7 — União  A | B
// -------------------------------------------------------
Conjunto Conjunto::operator|(const Conjunto& outro) const {
    Conjunto resultado(cap + outro.cap);
    for (int i = 0; i < tam; ++i) {
        resultado.adicionar(elementos[i]);
    }
    for (int i = 0; i < outro.tam; ++i) {
        if (!resultado.pertence(outro.elementos[i])) {
            resultado.adicionar(outro.elementos[i]);
        }
    }
    return resultado;
}

// -------------------------------------------------------
// Sobrecarga 8 — Interseção  A & B
// -------------------------------------------------------
Conjunto Conjunto::operator&(const Conjunto& outro) const {
    Conjunto resultado;
    for (int i = 0; i < tam; ++i) {
        if (outro.pertence(elementos[i])) {
            resultado.adicionar(elementos[i]);
        }
    }
    return resultado;
}

// -------------------------------------------------------
// Sobrecarga 9 — Diferença  A - B
// -------------------------------------------------------
Conjunto Conjunto::operator-(const Conjunto& outro) const {
    Conjunto resultado;
    for (int i = 0; i < tam; ++i) {
        if (!outro.pertence(elementos[i])) {
            resultado.adicionar(elementos[i]);
        }
    }
    return resultado;
}

// -------------------------------------------------------
// Impressão
// -------------------------------------------------------
std::ostream& Conjunto::imprimir(std::ostream& os) const {
    os << "{ ";
    for (int i = 0; i < tam; ++i) {
        os << elementos[i];
        if (i < tam - 1) {
            os << ", ";
        }
    }
    if (tam > 0) {
        os << " ";
    }
    os << "}";
    return os;
}

// Função livre — operador de saída
std::ostream& operator<<(std::ostream& os, const Conjunto& c) {
    return c.imprimir(os);
}