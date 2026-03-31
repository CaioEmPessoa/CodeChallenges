#include <iostream>
#include "../include/conjunto.hpp"
#include "../include/grafo.hpp"

int main() {

    // --------------------------------------------------
    // BLOCO 1: Conjunto e seus operadores
    // --------------------------------------------------
    std::cout << "=== BLOCO 1: Conjunto ===\n";

    Conjunto A, B;

    A += 1 += 2 += 3 += 4;   // operador +=
    B += 3 += 4 += 5 += 6;

    std::cout << "A = " << A << "\n";  // { 1, 2, 3, 4 }
    std::cout << "B = " << B << "\n";  // { 3, 4, 5, 6 }

    std::cout << "3 em A? " << (A << 3 ? "sim" : "nao") << "\n"; // sim
    std::cout << "5 em A? " << (A << 5 ? "sim" : "nao") << "\n"; // nao
    std::cout << "|A| = "   << ~A      << "\n";                   // 4

    Conjunto AuB = A | B;
    std::cout << "A | B = " << AuB << "\n"; // { 1, 2, 3, 4, 5, 6 }

    Conjunto AeB = A & B;
    std::cout << "A & B = " << AeB << "\n"; // { 3, 4 }

    Conjunto AmB = A - B;
    std::cout << "A - B = " << AmB << "\n"; // { 1, 2 }

    Conjunto C;
    C += 3 += 4;
    std::cout << "C <= A? " << (C <= A ? "sim" : "nao") << "\n"; // sim
    std::cout << "A <= B? " << (A <= B ? "sim" : "nao") << "\n"; // nao

    Conjunto D;
    D += 1 += 2 += 3 += 4;
    std::cout << "A == D? " << (A == D ? "sim" : "nao") << "\n"; // sim
    std::cout << "A != B? " << (A != B ? "sim" : "nao") << "\n"; // sim

    A.remover(4);
    std::cout << "A sem 4: " << A << "\n"; // { 1, 2, 3 }

    // --------------------------------------------------
    // BLOCO 2: Grafo — estrutura e operadores
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 2: Grafo (estrutura) ===\n";

    Grafo g(5);

    int e1[2] = {0, 1};
    int e2[2] = {0, 2};
    int e3[2] = {1, 3};
    int e4[2] = {2, 3};
    int e5[2] = {3, 4};

    g += e1; g += e2; g += e3; g += e4; g += e5;

    std::cout << g << "\n";

    int par1[2] = {0, 1};
    int par2[2] = {0, 4};
    std::cout << "Aresta 0->1? " << (g ^ par1 ? "sim" : "nao") << "\n"; // sim
    std::cout << "Aresta 0->4? " << (g ^ par2 ? "sim" : "nao") << "\n"; // nao
    std::cout << "Num arestas: " << ~g       << "\n";                    // 5
    std::cout << "Grau de 3:   " << g.grau(3) << "\n";                   // 3

    const int* viz = g(3);
    std::cout << "Vizinhos de 3: ";
    for (int i = 0; i < g.grau(3); i++)
        std::cout << viz[i] << " ";
    std::cout << "\n";

    std::cout << "Vertice 3? " << (g << 3 ? "sim" : "nao") << "\n"; // sim
    std::cout << "Vertice 9? " << (g << 9 ? "sim" : "nao") << "\n"; // nao

    // --------------------------------------------------
    // BLOCO 3: BFS
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 3: BFS ===\n";
    g.bfs(0);

    // --------------------------------------------------
    // BLOCO 4: DFS
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 4: DFS ===\n";
    g.dfs(0);

    // --------------------------------------------------
    // BLOCO 5: Caminhos
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 5: Caminhos ===\n";

    std::cout << "Caminho 0->4? "
              << (g.temCaminho(0, 4) ? "sim" : "nao") << "\n";
    std::cout << "Caminho 4->0? "
              << (g.temCaminho(4, 0) ? "sim" : "nao") << "\n";
    g.imprimirCaminho(0, 4);

    Grafo gDir(4, true);
    int d1[2] = {0,1}; int d2[2] = {1,2}; int d3[2] = {2,3};
    gDir += d1; gDir += d2; gDir += d3;
    std::cout << "Caminho 3->0 (dir)? "
              << (gDir.temCaminho(3, 0) ? "sim" : "nao") << "\n";
    gDir.imprimirCaminho(3, 0);

    // --------------------------------------------------
    // BLOCO 6: Circuito
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 6: Circuito ===\n";

    Grafo semCiclo(4, true);
    int sc1[2]={0,1}; int sc2[2]={1,2}; int sc3[2]={2,3};
    semCiclo += sc1; semCiclo += sc2; semCiclo += sc3;
    std::cout << "Tem circuito (DAG)? "
              << (semCiclo.temCircuito() ? "sim" : "nao") << "\n";

    Grafo comCiclo(4, true);
    int cc1[2]={0,1}; int cc2[2]={1,2}; int cc3[2]={2,0};
    comCiclo += cc1; comCiclo += cc2; comCiclo += cc3;
    std::cout << "Tem circuito (0->1->2->0)? "
              << (comCiclo.temCircuito() ? "sim" : "nao") << "\n";

    // --------------------------------------------------
    // BLOCO 7: Componentes Conexas
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 7: Componentes Conexas ===\n";

    Grafo gComp(7);
    int c1[2]={0,1}; int c2[2]={1,2}; int c3[2]={3,4};
    gComp += c1; gComp += c2; gComp += c3;
    std::cout << "Componentes: " << gComp.componentesConexas() << "\n"; // 4

    // --------------------------------------------------
    // BLOCO 8: Operações entre grafos
    // --------------------------------------------------
    std::cout << "\n=== BLOCO 8: Operacoes entre Grafos ===\n";

    Grafo g1(4), g2(4);
    int a1[2]={0,1}; int a2[2]={1,2};
    int a3[2]={2,3}; int a4[2]={0,3};
    g1 += a1; g1 += a2;
    g2 += a2; g2 += a3; g2 += a4;

    Grafo gUniao = g1 | g2;
    std::cout << "G1 | G2:\n" << gUniao << "\n";

    Grafo gInter = g1 & g2;
    std::cout << "G1 & G2:\n" << gInter << "\n";

    Grafo gDif = g1 - g2;
    std::cout << "G1 - G2:\n" << gDif << "\n";

    return 0;
}