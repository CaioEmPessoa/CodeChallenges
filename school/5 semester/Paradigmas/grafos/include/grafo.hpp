#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <stdexcept>
#include "conjunto.hpp"  // Grafo herda Conjunto

class Grafo : public Conjunto {

private:
    // Lista de adjacência alocada manualmente
    // adj[v]    : array de vizinhos do vértice v
    // adjTam[v] : quantos vizinhos v tem atualmente
    // adjCap[v] : capacidade da lista de v
    int** adj;
    int*  adjTam;
    int*  adjCap;
    int   numArestas;   // contador de arestas
    bool  direcionado;
    int   V;            // número de vértices (fixo)

    // Aloca as estruturas de adjacência para V vértices
    // adj = new int*[V]; adjTam/adjCap = new int[V]; adj[v] = new int[4]
    void alocarAdj();

    // Libera toda a memória das estruturas de adjacência
    // Para cada v: delete[] adj[v]; depois delete[] adj/adjTam/adjCap
    void liberarAdj();

    // Dobra a capacidade da lista de vizinhos do vértice v
    void crescerAdj(int v);

    // Auxiliar A — DFS que imprime cada vértice visitado
    // Usada por dfs()
    void dfsVisitar(int v, bool* vis) const;

    // Auxiliar B — DFS de alcançabilidade
    // Retorna true se consegue chegar de v até destino
    // Usada por temCaminho()
    bool dfsAlcanca(int v, int destino, bool* vis) const;

    // Auxiliar C — DFS com coloração para detectar circuito
    // cor: 0=não visitado  1=em visita  2=finalizado
    bool dfsCircuito(int v, int* cor) const;

    // Auxiliar D — DFS silenciosa (apenas marca visitados)
    // Usada por componentesConexas()
    void dfsMarcar(int v, bool* vis) const;

public:

    // Construtor
    // numVertices: quantidade de vértices (fixo após construção)
    // dir: true = grafo direcionado
    Grafo(int numVertices, bool dir = false);

    // TODO 3.5 — Construtor de cópia
    // Copiar adj, adjTam, adjCap, numArestas, direcionado, V
    Grafo(const Grafo& outro);

    // TODO 3.6 — Destrutor
    // Chamar liberarAdj()
    ~Grafo();

    // TODO 3.7 — Operador de atribuição
    // Guard, Conjunto::operator=(), liberarAdj, copiar, alocarAdj
    Grafo& operator=(const Grafo& outro);

    // Adiciona a aresta u -> v (e v -> u se não-direcionado)
    // Ignora se a aresta já existir
    // Lança std::out_of_range se u ou v forem inválidos
    void adicionarAresta(int u, int v);

    // Retorna true se existe aresta de u para v
    bool existeAresta(int u, int v) const;

    // Retorna o número de vizinhos do vértice v
    int grau(int v) const;

    // Sobrecarga 1 — Adicionar aresta  grafo += aresta
    // aresta deve ser int[2] com {u, v}
    // Uso:
    //   int e[2] = {0, 1};
    //   grafo += e;
    Grafo& operator+=(int* aresta);

    // Sobrecarga 2 — Vizinhos  grafo(v)
    // Retorna ponteiro para a lista de vizinhos de v
    // Uso: const int* viz = grafo(2);
    const int* operator()(int v) const;

    // Sobrecarga 3 — Número de arestas  ~grafo
    // Uso: int m = ~grafo;
    int operator~() const;

    // Sobrecarga 4 — Verificar aresta  grafo ^ par
    // par deve ser int[2] com {u, v}
    // Retorna true se a aresta u->v existe
    // Uso:
    //   int par[2] = {0, 1};
    //   if (grafo ^ par) { ... }
    bool operator^(int* par) const;

    // Sobrecarga 5 — União de grafos  G1 | G2
    // Retorna novo Grafo com todas as arestas de G1 e G2
    // Exige mesmo número de vértices
    Grafo operator|(const Grafo& outro) const;

    // Sobrecarga 6 — Interseção de grafos  G1 & G2
    // Retorna grafo com arestas presentes em ambos
    Grafo operator&(const Grafo& outro) const;

    // Sobrecarga 7 — Diferença de grafos  G1 - G2
    // Retorna grafo com arestas de G1 que não estão em G2
    Grafo operator-(const Grafo& outro) const;

    // Método de impressão do grafo
    // Exemplo de saída:
    //   [Grafo | V=5 | nao-direcionado]
    //   Vertices: { 0, 1, 2, 3, 4 }
    //   Arestas: 5
    //   Lista de adjacencia:
    //   0: [ 1 2 ]
    //   1: [ 0 3 ]
    std::ostream& imprimir(std::ostream& os) const;

    // ALGORITMO 1 — bfs
    // Imprime cada vértice visitado e sua distância em saltos
    // Saída: "Vertice X | distancia Y"
    void bfs(int origem) const;

    // ALGORITMO 2 — dfs
    // Imprime os vértices na ordem de visita
    // Saída: "DFS a partir de X:" seguido dos vértices
    void dfs(int origem) const;

    // ALGORITMO 3 — temCaminho
    // Retorna true se existe caminho de origem até destino
    bool temCaminho(int origem, int destino) const;

    // ALGORITMO 4 — imprimirCaminho
    // Imprime o caminho mais curto (em saltos) de origem a destino
    // Saída: "Caminho de X ate Y: 0 -> 1 -> 3 -> 4"
    // Se não houver: "Caminho inexistente"
    void imprimirCaminho(int origem, int destino) const;

    // ALGORITMO 5 — temCircuito
    // Retorna true se o grafo contém ao menos um circuito
    bool temCircuito() const;

    // ALGORITMO 6 — componentesConexas
    // Retorna o número de componentes conexas
    int componentesConexas() const;
};

// Operador de saída como função livre
std::ostream& operator<<(std::ostream& os, const Grafo& g);

#endif // GRAFO_HPP