#include "../include/grafo.hpp"

const int INF = 2147483647; // Representação de distância infinita

// -------------------------------------------------------
// TODO 3.1 — alocarAdj
// -------------------------------------------------------
void Grafo::alocarAdj() {
    adj = new int*[V];
    adjTam = new int[V];
    adjCap = new int[V];
    for (int i = 0; i < V; ++i) {
        adjTam[i] = 0;
        adjCap[i] = 4;
        adj[i] = new int[adjCap[i]];
    }
}

// -------------------------------------------------------
// TODO 3.2 — liberarAdj
// -------------------------------------------------------
void Grafo::liberarAdj() {
    for (int i = 0; i < V; ++i) {
        delete[] adj[i];
    }
    delete[] adj;
    delete[] adjTam;
    delete[] adjCap;
}

// -------------------------------------------------------
// TODO 3.3 — crescerAdj
// -------------------------------------------------------
void Grafo::crescerAdj(int v) {
    adjCap[v] *= 2;
    int* novo = new int[adjCap[v]];
    for (int i = 0; i < adjTam[v]; ++i) {
        novo[i] = adj[v][i];
    }
    delete[] adj[v];
    adj[v] = novo;
}

// -------------------------------------------------------
// Construtor
// -------------------------------------------------------
Grafo::Grafo(int numVertices, bool dir)
    : Conjunto(numVertices),
      V(numVertices),
      numArestas(0),
      direcionado(dir) {
    alocarAdj();
    for (int i = 0; i < V; i++) {
        adicionar(i);
    }
}

// -------------------------------------------------------
// TODO 3.5 — Construtor de cópia
// -------------------------------------------------------
Grafo::Grafo(const Grafo& outro)
    : Conjunto(outro),
      V(outro.V),
      numArestas(outro.numArestas),
      direcionado(outro.direcionado) {
    alocarAdj();
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < outro.adjTam[i]; ++j) {
            if (adjTam[i] == adjCap[i]) {
                crescerAdj(i);
            }
            adj[i][adjTam[i]++] = outro.adj[i][j];
        }
    }
}

// -------------------------------------------------------
// TODO 3.6 — Destrutor
// -------------------------------------------------------
Grafo::~Grafo() {
    liberarAdj();
}

// -------------------------------------------------------
// TODO 3.7 — Operador de atribuição
// -------------------------------------------------------
Grafo& Grafo::operator=(const Grafo& outro) {
    if (this == &outro) return *this;

    Conjunto::operator=(outro);
    liberarAdj(); // Usa o V antigo antes de atualizar

    V = outro.V;
    numArestas = outro.numArestas;
    direcionado = outro.direcionado;

    alocarAdj();
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < outro.adjTam[i]; ++j) {
            if (adjTam[i] == adjCap[i]) crescerAdj(i);
            adj[i][adjTam[i]++] = outro.adj[i][j];
        }
    }
    return *this;
}

// -------------------------------------------------------
// TODO 3.8 — adicionarAresta
// -------------------------------------------------------
void Grafo::adicionarAresta(int u, int v) {
    if (!pertence(u) || !pertence(v)) {
        throw std::out_of_range("Vertice invalido.");
    }
    if (existeAresta(u, v)) {
        return;
    }

    if (adjTam[u] == adjCap[u]) crescerAdj(u);
    adj[u][adjTam[u]++] = v;
    numArestas++;

    if (!direcionado) {
        if (adjTam[v] == adjCap[v]) crescerAdj(v);
        adj[v][adjTam[v]++] = u;
    }
}

// -------------------------------------------------------
// TODO 3.9 — existeAresta
// -------------------------------------------------------
bool Grafo::existeAresta(int u, int v) const {
    if (!pertence(u)) return false;
    for (int i = 0; i < adjTam[u]; ++i) {
        if (adj[u][i] == v) return true;
    }
    return false;
}

// -------------------------------------------------------
// TODO 3.14 — grau
// -------------------------------------------------------
int Grafo::grau(int v) const {
    if (!pertence(v)) throw std::out_of_range("Vertice invalido.");
    return adjTam[v];
}

// -------------------------------------------------------
// Sobrecarga 1 — operator+=
// -------------------------------------------------------
Grafo& Grafo::operator+=(int* aresta) {
    adicionarAresta(aresta[0], aresta[1]);
    return *this;
}

// -------------------------------------------------------
// Sobrecarga 2 — operator()
// -------------------------------------------------------
const int* Grafo::operator()(int v) const {
    if (!pertence(v)) throw std::out_of_range("Vertice invalido.");
    return adj[v];
}

// -------------------------------------------------------
// Sobrecarga 3 — operator~
// -------------------------------------------------------
int Grafo::operator~() const {
    return numArestas;
}

// -------------------------------------------------------
// Sobrecarga 4 — operator^
// -------------------------------------------------------
bool Grafo::operator^(int* par) const {
    return existeAresta(par[0], par[1]);
}

// -------------------------------------------------------
// Sobrecarga 5 — operator| (união de grafos)
// -------------------------------------------------------
Grafo Grafo::operator|(const Grafo& outro) const {
    if (V != outro.V) throw std::invalid_argument("Tamanhos incompativeis.");
    Grafo resultado(V, direcionado);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < adjTam[i]; ++j) {
            resultado.adicionarAresta(i, adj[i][j]);
        }
    }
    for (int i = 0; i < outro.V; ++i) {
        for (int j = 0; j < outro.adjTam[i]; ++j) {
            if (!resultado.existeAresta(i, outro.adj[i][j])) {
                resultado.adicionarAresta(i, outro.adj[i][j]);
            }
        }
    }
    return resultado;
}

// -------------------------------------------------------
// Sobrecarga 6 — operator& (interseção de grafos)
// -------------------------------------------------------
Grafo Grafo::operator&(const Grafo& outro) const {
    if (V != outro.V) throw std::invalid_argument("Tamanhos incompativeis.");
    Grafo resultado(V, direcionado);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < adjTam[i]; ++j) {
            int u = adj[i][j];
            if (outro.existeAresta(i, u)) {
                resultado.adicionarAresta(i, u);
            }
        }
    }
    return resultado;
}

// -------------------------------------------------------
// Sobrecarga 7 — operator- (diferença de grafos)
// -------------------------------------------------------
Grafo Grafo::operator-(const Grafo& outro) const {
    if (V != outro.V) throw std::invalid_argument("Tamanhos incompativeis.");
    Grafo resultado(V, direcionado);

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < adjTam[i]; ++j) {
            int u = adj[i][j];
            if (!outro.existeAresta(i, u)) {
                resultado.adicionarAresta(i, u);
            }
        }
    }
    return resultado;
}

// -------------------------------------------------------
// Impressão
// -------------------------------------------------------
std::ostream& Grafo::imprimir(std::ostream& os) const {
    os << "[Grafo | V=" << V << " | " << (direcionado ? "direcionado" : "nao-direcionado") << "]\n";
    os << "Vertices: ";
    Conjunto::imprimir(os);
    os << "\n";
    os << "Arestas: " << numArestas << "\n";
    os << "Lista de adjacencia:\n";
    for (int i = 0; i < V; ++i) {
        os << i << ": [ ";
        for (int j = 0; j < adjTam[i]; ++j) {
            os << adj[i][j] << " ";
        }
        os << "]\n";
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Grafo& g) {
    return g.imprimir(os);
}

// -------------------------------------------------------
// Auxiliar A — dfsVisitar
// -------------------------------------------------------
void Grafo::dfsVisitar(int v, bool* vis) const {
    vis[v] = true;
    std::cout << v << " ";
    for (int i = 0; i < adjTam[v]; ++i) {
        int u = adj[v][i];
        if (!vis[u]) {
            dfsVisitar(u, vis);
        }
    }
}

// -------------------------------------------------------
// Auxiliar B — dfsAlcanca
// -------------------------------------------------------
bool Grafo::dfsAlcanca(int v, int destino, bool* vis) const {
    if (v == destino) return true;
    vis[v] = true;
    for (int i = 0; i < adjTam[v]; ++i) {
        int u = adj[v][i];
        if (!vis[u] && dfsAlcanca(u, destino, vis)) {
            return true;
        }
    }
    return false;
}

// -------------------------------------------------------
// Auxiliar C — dfsCircuito
// -------------------------------------------------------
bool Grafo::dfsCircuito(int v, int* cor) const {
    cor[v] = 1;
    for (int i = 0; i < adjTam[v]; ++i) {
        int u = adj[v][i];
        if (cor[u] == 1) return true;
        if (cor[u] == 0 && dfsCircuito(u, cor)) return true;
    }
    cor[v] = 2;
    return false;
}

// -------------------------------------------------------
// Auxiliar D — dfsMarcar
// -------------------------------------------------------
void Grafo::dfsMarcar(int v, bool* vis) const {
    vis[v] = true;
    for (int i = 0; i < adjTam[v]; ++i) {
        int u = adj[v][i];
        if (!vis[u]) dfsMarcar(u, vis);
    }
}

// -------------------------------------------------------
// ALGORITMO 1 — bfs
// -------------------------------------------------------
void Grafo::bfs(int origem) const {
    if (!pertence(origem)) throw std::out_of_range("Vertice invalido.");

    bool* vis = new bool[V];
    int* dist = new int[V];
    int* fila = new int[V];

    for(int i = 0; i < V; ++i) {
        vis[i] = false;
        dist[i] = INF;
    }

    int ini = 0, fim = 0;
    vis[origem] = true;
    dist[origem] = 0;
    fila[fim++] = origem;

    while (ini < fim) {
        int u = fila[ini++];
        std::cout << "Vertice " << u << " | distancia " << dist[u] << "\n";

        for (int i = 0; i < adjTam[u]; ++i) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                fila[fim++] = v;
            }
        }
    }

    delete[] vis;
    delete[] dist;
    delete[] fila;
}

// -------------------------------------------------------
// ALGORITMO 2 — dfs
// -------------------------------------------------------
void Grafo::dfs(int origem) const {
    if (!pertence(origem)) throw std::out_of_range("Vertice invalido.");

    bool* vis = new bool[V];
    for (int i = 0; i < V; ++i) vis[i] = false;

    std::cout << "DFS a partir de " << origem << ": ";
    dfsVisitar(origem, vis);
    std::cout << "\n";

    delete[] vis;
}

// -------------------------------------------------------
// ALGORITMO 3 — temCaminho
// -------------------------------------------------------
bool Grafo::temCaminho(int origem, int destino) const {
    if (!pertence(origem) || !pertence(destino)) {
        throw std::out_of_range("Vertice invalido.");
    }

    bool* vis = new bool[V];
    for (int i = 0; i < V; ++i) vis[i] = false;

    bool r = dfsAlcanca(origem, destino, vis);
    delete[] vis;

    return r;
}

// -------------------------------------------------------
// ALGORITMO 4 — imprimirCaminho
// -------------------------------------------------------
void Grafo::imprimirCaminho(int origem, int destino) const {
    if (!pertence(origem) || !pertence(destino)) {
        throw std::out_of_range("Vertice invalido.");
    }

    bool* vis = new bool[V];
    int* anterior = new int[V];
    int* fila = new int[V];

    for (int i = 0; i < V; ++i) {
        vis[i] = false;
        anterior[i] = -1;
    }

    int ini = 0, fim = 0;
    vis[origem] = true;
    fila[fim++] = origem;

    while (ini < fim) {
        int u = fila[ini++];
        if (u == destino) break;

        for (int i = 0; i < adjTam[u]; ++i) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = true;
                anterior[v] = u;
                fila[fim++] = v;
            }
        }
    }

    if (anterior[destino] == -1 && origem != destino) {
        std::cout << "Caminho inexistente\n";
    } else {
        int* caminho = new int[V];
        int atual = destino;
        int cTam = 0;

        while (atual != -1) {
            caminho[cTam++] = atual;
            atual = anterior[atual];
        }

        std::cout << "Caminho de " << origem << " ate " << destino << ": ";
        for (int i = cTam - 1; i >= 0; --i) {
            std::cout << caminho[i];
            if (i > 0) std::cout << " -> ";
        }
        std::cout << "\n";
        delete[] caminho;
    }

    delete[] vis;
    delete[] anterior;
    delete[] fila;
}

// -------------------------------------------------------
// ALGORITMO 5 — temCircuito
// -------------------------------------------------------
bool Grafo::temCircuito() const {
    int* cor = new int[V];
    for (int i = 0; i < V; ++i) cor[i] = 0;

    for (int v = 0; v < V; ++v) {
        if (cor[v] == 0 && dfsCircuito(v, cor)) {
            delete[] cor;
            return true;
        }
    }
    delete[] cor;
    return false;
}

// -------------------------------------------------------
// ALGORITMO 6 — componentesConexas
// -------------------------------------------------------
int Grafo::componentesConexas() const {
    bool* vis = new bool[V];
    for (int i = 0; i < V; ++i) vis[i] = false;

    int count = 0;
    for (int v = 0; v < V; ++v) {
        if (!vis[v]) {
            dfsMarcar(v, vis);
            count++;
        }
    }

    delete[] vis;
    return count;
}