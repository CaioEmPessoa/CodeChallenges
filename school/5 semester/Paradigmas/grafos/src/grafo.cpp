#include "../include/grafo.hpp"

// -------------------------------------------------------
// TODO 3.1 — alocarAdj
// -------------------------------------------------------
void Grafo::alocarAdj() {
    // adj     = new int*[V]
    // adjTam  = new int[V]  (zerar todos)
    // adjCap  = new int[V]  (inicializar com 4)
    // Para cada v: adj[v] = new int[adjCap[v]]
}

// -------------------------------------------------------
// TODO 3.2 — liberarAdj
// -------------------------------------------------------
void Grafo::liberarAdj() {
    // Para cada v: delete[] adj[v]
    // delete[] adj; delete[] adjTam; delete[] adjCap
}

// -------------------------------------------------------
// TODO 3.3 — crescerAdj
// -------------------------------------------------------
void Grafo::crescerAdj(int v) {
    // adjCap[v] *= 2
    // int* novo = new int[adjCap[v]]
    // Copiar adjTam[v] elementos
    // delete[] adj[v]; adj[v] = novo
}

// -------------------------------------------------------
// Construtor
// -------------------------------------------------------
Grafo::Grafo(int numVertices, bool dir)
    : Conjunto(numVertices),
      V(numVertices),
      numArestas(0),
      direcionado(dir) {
    // TODO 3.4:
    // Chamar alocarAdj()
    // Adicionar vértices 0..V-1 ao Conjunto herdado:
    //   for (int i = 0; i < V; i++) adicionar(i)
}

// -------------------------------------------------------
// TODO 3.5 — Construtor de cópia
// -------------------------------------------------------
Grafo::Grafo(const Grafo& outro)
    : Conjunto(outro),
      V(outro.V),
      numArestas(outro.numArestas),
      direcionado(outro.direcionado) {
    // Chamar alocarAdj()
    // Para cada v, copiar adjTam[v] vizinhos de outro.adj[v]
}

// -------------------------------------------------------
// TODO 3.6 — Destrutor
// -------------------------------------------------------
Grafo::~Grafo() {
    // liberarAdj()
}

// -------------------------------------------------------
// TODO 3.7 — Operador de atribuição
// -------------------------------------------------------
Grafo& Grafo::operator=(const Grafo& outro) {
    // Guard: if (this == &outro) return *this
    // Conjunto::operator=(outro)
    // liberarAdj()
    // Copiar V, numArestas, direcionado
    // alocarAdj()
    // Copiar listas de adjacência
    // return *this
}

// -------------------------------------------------------
// TODO 3.8 — adicionarAresta
// -------------------------------------------------------
void Grafo::adicionarAresta(int u, int v) {
    // Se !pertence(u) || !pertence(v): lançar std::out_of_range
    // Se existeAresta(u, v): return
    // Se adjTam[u] == adjCap[u]: crescerAdj(u)
    // adj[u][adjTam[u]++] = v; numArestas++
    // Se não-direcionado:
    //   Se adjTam[v] == adjCap[v]: crescerAdj(v)
    //   adj[v][adjTam[v]++] = u
}

// -------------------------------------------------------
// TODO 3.9 — existeAresta
// -------------------------------------------------------
bool Grafo::existeAresta(int u, int v) const {
    // Se !pertence(u): return false
    // Percorrer adj[u][0..adjTam[u]-1]
    // Retornar true se algum for igual a v
}

// -------------------------------------------------------
// TODO 3.14 — grau
// -------------------------------------------------------
int Grafo::grau(int v) const {
    // Se !pertence(v): lançar exceção
    // return adjTam[v]
}

// -------------------------------------------------------
// Sobrecarga 1 — operator+=
// -------------------------------------------------------
Grafo& Grafo::operator+=(int* aresta) {
    // TODO 3.10:
    // adicionarAresta(aresta[0], aresta[1]); return *this
}

// -------------------------------------------------------
// Sobrecarga 2 — operator()
// -------------------------------------------------------
const int* Grafo::operator()(int v) const {
    // TODO 3.11:
    // Se !pertence(v): lançar exceção
    // return adj[v]
}

// -------------------------------------------------------
// Sobrecarga 3 — operator~
// -------------------------------------------------------
int Grafo::operator~() const {
    // TODO 3.12: return numArestas
}

// -------------------------------------------------------
// Sobrecarga 4 — operator^
// -------------------------------------------------------
bool Grafo::operator^(int* par) const {
    // TODO 3.13: return existeAresta(par[0], par[1])
}

// -------------------------------------------------------
// Sobrecarga 5 — operator| (união de grafos)
// -------------------------------------------------------
Grafo Grafo::operator|(const Grafo& outro) const {
    // TODO 5.1:
    // Se V != outro.V: lançar std::invalid_argument
    // Grafo resultado(V, direcionado)
    // Adicionar todas as arestas de *this
    // Adicionar arestas de outro que ainda não existam
    // return resultado
}

// -------------------------------------------------------
// Sobrecarga 6 — operator& (interseção de grafos)
// -------------------------------------------------------
Grafo Grafo::operator&(const Grafo& outro) const {
    // TODO 5.2:
    // Se V != outro.V: lançar exceção
    // Para cada aresta (v, u) de *this:
    //   Se outro.existeAresta(v, u): resultado.adicionarAresta(v, u)
    // return resultado
}

// -------------------------------------------------------
// Sobrecarga 7 — operator- (diferença de grafos)
// -------------------------------------------------------
Grafo Grafo::operator-(const Grafo& outro) const {
    // TODO 5.3:
    // Para cada aresta (v, u) de *this:
    //   Se !outro.existeAresta(v, u): resultado.adicionarAresta(v, u)
    // return resultado
}

// -------------------------------------------------------
// Impressão
// -------------------------------------------------------
std::ostream& Grafo::imprimir(std::ostream& os) const {
    // TODO 3.15:
    // Imprimir cabeçalho: [Grafo | V=X | nao-direcionado]
    // Imprimir vértices chamando Conjunto::imprimir(os)
    // Imprimir numArestas
    // Para cada vértice v, imprimir adj[v][0..adjTam[v]-1]
}

std::ostream& operator<<(std::ostream& os, const Grafo& g) {
    return g.imprimir(os);
}

// -------------------------------------------------------
// Auxiliar A — dfsVisitar
// -------------------------------------------------------
void Grafo::dfsVisitar(int v, bool* vis) const {
    // TODO 3.A.1:
    // vis[v] = true; imprimir v
    // Para cada vizinho u em adj[v][0..adjTam[v]-1]:
    //   Se !vis[u]: dfsVisitar(u, vis)
}

// -------------------------------------------------------
// Auxiliar B — dfsAlcanca
// -------------------------------------------------------
bool Grafo::dfsAlcanca(int v, int destino, bool* vis) const {
    // TODO 3.A.2:
    // Se v == destino: return true
    // vis[v] = true
    // Para cada vizinho u: se !vis[u] && dfsAlcanca(u,...): return true
    // return false
}

// -------------------------------------------------------
// Auxiliar C — dfsCircuito
// -------------------------------------------------------
bool Grafo::dfsCircuito(int v, int* cor) const {
    // TODO 3.A.3:
    // cor[v] = 1
    // Para cada vizinho u:
    //   Se cor[u] == 1: return true
    //   Se cor[u] == 0 && dfsCircuito(u, cor): return true
    // cor[v] = 2; return false
}

// -------------------------------------------------------
// Auxiliar D — dfsMarcar
// -------------------------------------------------------
void Grafo::dfsMarcar(int v, bool* vis) const {
    // TODO 3.A.4:
    // vis[v] = true
    // Para cada vizinho u: se !vis[u]: dfsMarcar(u, vis)
}

// -------------------------------------------------------
// ALGORITMO 1 — bfs
// -------------------------------------------------------
void Grafo::bfs(int origem) const {
    // TODO 4.1:
    // Se !pertence(origem): lançar exceção
    // bool* vis  = new bool[V]  (false)
    // int*  dist = new int[V]   (INF)
    // int*  fila = new int[V]
    // int ini = 0, fim = 0
    // vis[origem] = true; dist[origem] = 0; fila[fim++] = origem
    // while (ini < fim):
    //   u = fila[ini++]; imprimir u e dist[u]
    //   Para cada vizinho v de u:
    //     Se !vis[v]: vis[v]=true; dist[v]=dist[u]+1; fila[fim++]=v
    // delete[] vis; delete[] dist; delete[] fila
}

// -------------------------------------------------------
// ALGORITMO 2 — dfs
// -------------------------------------------------------
void Grafo::dfs(int origem) const {
    // TODO 4.2:
    // Se !pertence(origem): lançar exceção
    // bool* vis = new bool[V]  (false)
    // Imprimir "DFS a partir de X:"
    // dfsVisitar(origem, vis)
    // delete[] vis
}

// -------------------------------------------------------
// ALGORITMO 3 — temCaminho
// -------------------------------------------------------
bool Grafo::temCaminho(int origem, int destino) const {
    // TODO 4.3:
    // Se !pertence(origem) || !pertence(destino): lançar exceção
    // bool* vis = new bool[V]  (false)
    // bool r = dfsAlcanca(origem, destino, vis)
    // delete[] vis; return r
}

// -------------------------------------------------------
// ALGORITMO 4 — imprimirCaminho
// -------------------------------------------------------
void Grafo::imprimirCaminho(int origem, int destino) const {
    // TODO 4.4:
    // BFS mantendo int* anterior = new int[V] (iniciado com -1)
    // Ao visitar u via v: anterior[u] = v
    // Se anterior[destino] == -1 && origem != destino:
    //   Imprimir "Caminho inexistente"
    // Senão: reconstruir com int* caminho = new int[V]
    //   int atual = destino; cTam = 0
    //   while (atual != -1): caminho[cTam++] = atual; atual = anterior[atual]
    //   Imprimir do fim para o início com " -> " entre vértices
    // delete[] vis; delete[] anterior; delete[] fila; delete[] caminho
}

// -------------------------------------------------------
// ALGORITMO 5 — temCircuito
// -------------------------------------------------------
bool Grafo::temCircuito() const {
    // TODO 4.5:
    // int* cor = new int[V]  (0)
    // Para cada v: se cor[v]==0 && dfsCircuito(v,cor): delete[] cor; return true
    // delete[] cor; return false
}

// -------------------------------------------------------
// ALGORITMO 6 — componentesConexas
// -------------------------------------------------------
int Grafo::componentesConexas() const {
    // TODO 4.6:
    // bool* vis = new bool[V]  (false)
    // int count = 0
    // Para cada v: se !vis[v]: dfsMarcar(v,vis); count++
    // delete[] vis; return count
}