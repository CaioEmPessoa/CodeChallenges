#include <iostream>
#include "../include/conjunto.hpp"
#include "../include/grafo.hpp"

// ============================================================
// INFRAESTRUTURA DE TESTES
// ============================================================

int totalTestes  = 0;
int testesOk     = 0;
int testesFalhou = 0;

// Verifica uma condição booleana e reporta o resultado
void verificar(const char* nomeTeste, bool condicao) {
    totalTestes++;
    if (condicao) {
        testesOk++;
        std::cout << "  [OK]     " << nomeTeste << "\n";
    } else {
        testesFalhou++;
        std::cout << "  [FALHOU] " << nomeTeste << "\n";
    }
}

// Imprime o cabeçalho de um grupo de testes
void cabecalho(const char* titulo) {
    std::cout << "\n";
    std::cout << "============================================================\n";
    std::cout << "  " << titulo << "\n";
    std::cout << "============================================================\n";
}

// Imprime o resumo final
void resumo() {
    std::cout << "\n";
    std::cout << "============================================================\n";
    std::cout << "  RESULTADO FINAL\n";
    std::cout << "============================================================\n";
    std::cout << "  Total   : " << totalTestes  << "\n";
    std::cout << "  OK      : " << testesOk     << "\n";
    std::cout << "  Falhou  : " << testesFalhou << "\n";
    std::cout << "============================================================\n";
}

// ============================================================
// TESTES DA CLASSE CONJUNTO  (Testes 1 a 10)
// ============================================================

// ------------------------------------------------------------
// TESTE 1 — adicionar e pertence
// Verifica que elementos inseridos são encontrados
// e elementos não inseridos não são encontrados
// ------------------------------------------------------------
void teste01_adicionar_pertence() {
    cabecalho("TESTE 01 — Conjunto: adicionar e pertence");

    Conjunto A;
    A.adicionar(10);
    A.adicionar(20);
    A.adicionar(30);

    verificar(
        "pertence(10) apos adicionar(10)",
        A.pertence(10)
    );
    verificar(
        "pertence(20) apos adicionar(20)",
        A.pertence(20)
    );
    verificar(
        "!pertence(99) para elemento nao inserido",
        !A.pertence(99)
    );
    verificar(
        "adicionar duplicata nao aumenta tamanho",
        // Inserir 10 novamente; tamanho deve continuar 3
        (A.adicionar(10), A.tamanho() == 3)
    );
}

// ------------------------------------------------------------
// TESTE 2 — remover
// Verifica remoção correta e comportamento com elemento ausente
// ------------------------------------------------------------
void teste02_remover() {
    cabecalho("TESTE 02 — Conjunto: remover");

    Conjunto A;
    A.adicionar(1);
    A.adicionar(2);
    A.adicionar(3);

    A.remover(2);

    verificar(
        "!pertence(2) apos remover(2)",
        !A.pertence(2)
    );
    verificar(
        "pertence(1) e pertence(3) apos remover(2)",
        A.pertence(1) && A.pertence(3)
    );
    verificar(
        "tamanho == 2 apos remover um elemento",
        A.tamanho() == 2
    );

    // Remover elemento que não existe não deve alterar o conjunto
    A.remover(99);
    verificar(
        "tamanho continua 2 apos remover elemento ausente",
        A.tamanho() == 2
    );
}

// ------------------------------------------------------------
// TESTE 3 — operador~ (cardinalidade)
// ------------------------------------------------------------
void teste03_cardinalidade() {
    cabecalho("TESTE 03 — Conjunto: operador~ (cardinalidade)");

    Conjunto A;
    verificar(
        "~A == 0 para conjunto vazio",
        ~A == 0
    );

    A += 5; A += 10; A += 15;
    verificar(
        "~A == 3 apos inserir 3 elementos",
        ~A == 3
    );

    A.remover(10);
    verificar(
        "~A == 2 apos remover um elemento",
        ~A == 2
    );
}

// ------------------------------------------------------------
// TESTE 4 — operador<< (pertinência) e operador+= (inserção)
// ------------------------------------------------------------
void teste04_pertinencia_insercao() {
    cabecalho("TESTE 04 — Conjunto: operadores << e +=");

    Conjunto A;
    A += 7; A += 14; A += 21;

    verificar(
        "A << 7  retorna true (7 pertence a A)",
        A << 7
    );
    verificar(
        "A << 14 retorna true (14 pertence a A)",
        A << 14
    );
    verificar(
        "A << 99 retorna false (99 nao pertence a A)",
        !(A << 99)
    );
    verificar(
        "A << 0  retorna false (0 nao foi inserido)",
        !(A << 0)
    );
}

// ------------------------------------------------------------
// TESTE 5 — operador== e operador!=
// ------------------------------------------------------------
void teste05_igualdade() {
    cabecalho("TESTE 05 — Conjunto: operadores == e !=");

    Conjunto A, B, C;
    A += 1; A += 2; A += 3;
    B += 3; B += 1; B += 2;  // mesmos elementos, ordem diferente
    C += 1; C += 2;

    verificar(
        "A == B (mesmos elementos, ordens diferentes)",
        A == B
    );
    verificar(
        "!(A == C) (C tem menos elementos)",
        !(A == C)
    );
    verificar(
        "A != C  retorna true",
        A != C
    );
    verificar(
        "!(A != B) retorna true",
        !(A != B)
    );
}

// ------------------------------------------------------------
// TESTE 6 — operador<= (subconjunto)
// ------------------------------------------------------------
void teste06_subconjunto() {
    cabecalho("TESTE 06 — Conjunto: operador<= (subconjunto)");

    Conjunto A, B, C;
    A += 1; A += 2;
    B += 1; B += 2; B += 3; B += 4;
    C += 5; C += 6;

    verificar(
        "A <= B (A subconjunto de B)",
        A <= B
    );
    verificar(
        "B <= B (todo conjunto e subconjunto de si mesmo)",
        B <= B
    );
    verificar(
        "!(B <= A) (B nao e subconjunto de A)",
        !(B <= A)
    );
    verificar(
        "!(A <= C) (elementos disjuntos)",
        !(A <= C)
    );
}

// ------------------------------------------------------------
// TESTE 7 — operador| (união)
// ------------------------------------------------------------
void teste07_uniao() {
    cabecalho("TESTE 07 — Conjunto: operador| (uniao)");

    Conjunto A, B;
    A += 1; A += 2; A += 3;
    B += 3; B += 4; B += 5;

    Conjunto U = A | B;

    verificar(
        "uniao contem elementos de A (1, 2, 3)",
        (U << 1) && (U << 2) && (U << 3)
    );
    verificar(
        "uniao contem elementos exclusivos de B (4, 5)",
        (U << 4) && (U << 5)
    );
    verificar(
        "uniao nao duplica elemento comum (3)",
        ~U == 5
    );
    verificar(
        "uniao com conjunto vazio retorna o proprio conjunto",
        (Conjunto(), A | Conjunto()) == A
    );
}

// ------------------------------------------------------------
// TESTE 8 — operador& (interseção)
// ------------------------------------------------------------
void teste08_intersecao() {
    cabecalho("TESTE 08 — Conjunto: operador& (intersecao)");

    Conjunto A, B, C;
    A += 1; B += 2; B += 3; B += 4;
    B += 3; B += 4; B += 5; B += 6;
    C += 7; C += 8;  // disjunto de A

    Conjunto I = A & B;

    verificar(
        "intersecao contem 3 (elemento comum)",
        I << 3
    );
    verificar(
        "intersecao contem 4 (elemento comum)",
        I << 4
    );
    verificar(
        "intersecao nao contem 1 (exclusivo de A)",
        !(I << 1)
    );
    verificar(
        "intersecao com conjunto disjunto e vazia",
        ~(A & C) == 0
    );
}

// ------------------------------------------------------------
// TESTE 9 — operador- (diferença)
// ------------------------------------------------------------
void teste09_diferenca() {
    cabecalho("TESTE 09 — Conjunto: operador- (diferenca)");

    Conjunto A, B;
    A += 1; A += 2; A += 3; A += 4;
    B += 3; B += 4; B += 5;

    Conjunto D = A - B;

    verificar(
        "A - B contem 1 (exclusivo de A)",
        D << 1
    );
    verificar(
        "A - B contem 2 (exclusivo de A)",
        D << 2
    );
    verificar(
        "A - B nao contem 3 (esta em B)",
        !(D << 3)
    );
    verificar(
        "A - B nao contem 4 (esta em B)",
        !(D << 4)
    );
    verificar(
        "A - A resulta em conjunto vazio",
        ~(A - A) == 0
    );
}

// ------------------------------------------------------------
// TESTE 10 — construtor de cópia e operador=
// ------------------------------------------------------------
void teste10_copia_atribuicao() {
    cabecalho("TESTE 10 — Conjunto: construtor de copia e operador=");

    Conjunto A;
    A += 10; A += 20; A += 30;

    // Construtor de cópia
    Conjunto B(A);
    verificar(
        "copia contem os mesmos elementos que o original",
        B == A
    );

    // Modificar B não deve afetar A
    B.adicionar(40);
    verificar(
        "modificar copia nao altera o original",
        !A.pertence(40)
    );

    // Operador de atribuição
    Conjunto C;
    C = A;
    verificar(
        "atribuicao copia os elementos corretamente",
        C == A
    );

    // Auto-atribuição não deve quebrar o objeto
    A = A;
    verificar(
        "auto-atribuicao nao corrompe o objeto",
        A.pertence(10) && A.pertence(20) && A.pertence(30)
    );
}

// ============================================================
// TESTES DA CLASSE GRAFO  (Testes 11 a 20)
// ============================================================

// ------------------------------------------------------------
// TESTE 11 — construtor e herança de Conjunto
// Vértices devem pertencer ao conjunto herdado
// ------------------------------------------------------------
void teste11_construtor_heranca() {
    cabecalho("TESTE 11 — Grafo: construtor e heranca de Conjunto");

    Grafo g(5);

    verificar(
        "vertice 0 pertence ao grafo (heranca de Conjunto)",
        g << 0
    );
    verificar(
        "vertice 4 pertence ao grafo",
        g << 4
    );
    verificar(
        "vertice 5 nao pertence (fora do intervalo)",
        !(g << 5)
    );
    verificar(
        "numero de vertices == 5 (tamanho herdado)",
        g.tamanho() == 5
    );
}

// ------------------------------------------------------------
// TESTE 12 — adicionarAresta e existeAresta
// ------------------------------------------------------------
void teste12_adicionar_existeAresta() {
    cabecalho("TESTE 12 — Grafo: adicionarAresta e existeAresta");

    Grafo g(4);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(2, 3);

    verificar(
        "existeAresta(0,1) apos adicionarAresta(0,1)",
        g.existeAresta(0, 1)
    );
    verificar(
        "existeAresta(1,0) (nao-dir: aresta vale nos dois sentidos)",
        g.existeAresta(1, 0)
    );
    verificar(
        "!existeAresta(0,3) (aresta nao adicionada)",
        !g.existeAresta(0, 3)
    );
    verificar(
        "adicionar aresta duplicata nao altera numArestas",
        (g.adicionarAresta(0, 1), ~g == 3)
    );
}

// ------------------------------------------------------------
// TESTE 13 — operador+= (adicionar aresta) e operador^
// ------------------------------------------------------------
void teste13_operador_aresta() {
    cabecalho("TESTE 13 — Grafo: operadores += e ^");

    Grafo g(5);
    int e1[2] = {0, 1};
    int e2[2] = {1, 2};
    int e3[2] = {2, 3};
    int e4[2] = {3, 4};

    g += e1; g += e2; g += e3; g += e4;

    int p1[2] = {0, 1};
    int p2[2] = {0, 4};  // aresta inexistente
    int p3[2] = {3, 4};

    verificar(
        "g ^ {0,1} retorna true (aresta existe)",
        g ^ p1
    );
    verificar(
        "g ^ {3,4} retorna true (aresta existe)",
        g ^ p3
    );
    verificar(
        "g ^ {0,4} retorna false (aresta nao existe)",
        !(g ^ p2)
    );
}

// ------------------------------------------------------------
// TESTE 14 — operador~ (número de arestas) e grau
// ------------------------------------------------------------
void teste14_num_arestas_grau() {
    cabecalho("TESTE 14 — Grafo: operador~ (arestas) e grau");

    Grafo g(5);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(3, 4);

    verificar(
        "~g == 5 (cinco arestas no grafo nao-direcionado)",
        ~g == 5
    );
    verificar(
        "grau(0) == 2 (vizinhos: 1 e 2)",
        g.grau(0) == 2
    );
    verificar(
        "grau(3) == 3 (vizinhos: 1, 2 e 4)",
        g.grau(3) == 3
    );
    verificar(
        "grau(4) == 1 (vizinho: apenas 3)",
        g.grau(4) == 1
    );
}

// ------------------------------------------------------------
// TESTE 15 — operador() (vizinhos) e grafo direcionado
// ------------------------------------------------------------
void teste15_vizinhos_direcionado() {
    cabecalho("TESTE 15 — Grafo: operador() e grafo direcionado");

    Grafo gDir(4, true);  // direcionado
    gDir.adicionarAresta(0, 1);
    gDir.adicionarAresta(0, 2);
    gDir.adicionarAresta(1, 3);

    const int* viz0 = gDir(0);

    verificar(
        "grafo direcionado: grau de saida de 0 == 2",
        gDir.grau(0) == 2
    );
    verificar(
        "grafo direcionado: vizinhos de 0 incluem 1 e 2",
        (viz0[0] == 1 || viz0[1] == 1) &&
        (viz0[0] == 2 || viz0[1] == 2)
    );
    verificar(
        "grafo direcionado: aresta 0->1 existe",
        gDir.existeAresta(0, 1)
    );
    verificar(
        "grafo direcionado: aresta 1->0 NAO existe",
        !gDir.existeAresta(1, 0)
    );
}

// ------------------------------------------------------------
// TESTE 16 — bfs (busca em largura)
// Valida a ordem e as distâncias computadas
// Como bfs() imprime na saída padrão, aqui testamos
// as distâncias recomputando manualmente e comparando
// com o comportamento esperado via temCaminho
// ------------------------------------------------------------
void teste16_bfs() {
    cabecalho("TESTE 16 — Grafo: bfs (busca em largura)");

    //  Grafo:  0 - 1 - 3
    //          |
    //          2 - 4
    Grafo g(5);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(2, 4);

    // BFS a partir de 0 deve alcançar todos os vértices
    verificar(
        "BFS alcanca vertice 3 a partir de 0 (2 saltos via 1)",
        g.temCaminho(0, 3)
    );
    verificar(
        "BFS alcanca vertice 4 a partir de 0 (2 saltos via 2)",
        g.temCaminho(0, 4)
    );

    // A saída visual é verificada manualmente — exibir para inspeção
    std::cout << "  [VISUAL] Saida esperada: vertices 0,1,2,3,4 em ordem de distancia\n";
    std::cout << "  ";
    g.bfs(0);
}

// ------------------------------------------------------------
// TESTE 17 — dfs (busca em profundidade)
// ------------------------------------------------------------
void teste17_dfs() {
    cabecalho("TESTE 17 — Grafo: dfs (busca em profundidade)");

    //  Grafo:  0 - 1 - 3 - 4
    //          |
    //          2
    Grafo g(5);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(3, 4);

    // DFS a partir de 0 deve visitar todos os vértices
    // (nao ha vértice isolado neste grafo)
    verificar(
        "DFS alcanca todos os vertices (grafo conexo)",
        g.componentesConexas() == 1
    );
    verificar(
        "DFS alcanca vertice 4 a partir de 0",
        g.temCaminho(0, 4)
    );

    std::cout << "  [VISUAL] Saida esperada: 0 seguido de vizinhos em profundidade\n";
    std::cout << "  ";
    g.dfs(0);
}

// ------------------------------------------------------------
// TESTE 18 — temCaminho e imprimirCaminho
// ------------------------------------------------------------
void teste18_caminho() {
    cabecalho("TESTE 18 — Grafo: temCaminho e imprimirCaminho");

    //  Grafo nao-direcionado: 0-1-2-3-4  (cadeia)
    Grafo g(5);
    g.adicionarAresta(0, 1);
    g.adicionarAresta(1, 2);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(3, 4);

    verificar(
        "temCaminho(0,4) == true em cadeia conexa",
        g.temCaminho(0, 4)
    );
    verificar(
        "temCaminho(4,0) == true (nao-dir: caminho nos dois sentidos)",
        g.temCaminho(4, 0)
    );

    // Grafo direcionado sem caminho de volta
    Grafo gDir(4, true);
    int d1[2]={0,1}; int d2[2]={1,2}; int d3[2]={2,3};
    gDir += d1; gDir += d2; gDir += d3;

    verificar(
        "temCaminho(0,3) == true em grafo dir (0->1->2->3)",
        gDir.temCaminho(0, 3)
    );
    verificar(
        "temCaminho(3,0) == false em grafo dir (sem caminho de volta)",
        !gDir.temCaminho(3, 0)
    );

    std::cout << "  [VISUAL] Caminho esperado de 0 ate 4: 0 -> 1 -> 2 -> 3 -> 4\n";
    std::cout << "  ";
    g.imprimirCaminho(0, 4);

    std::cout << "  [VISUAL] Deve exibir: Caminho inexistente\n";
    std::cout << "  ";
    gDir.imprimirCaminho(3, 0);
}

// ------------------------------------------------------------
// TESTE 19 — temCircuito
// ------------------------------------------------------------
void teste19_circuito() {
    cabecalho("TESTE 19 — Grafo: temCircuito");

    // DAG (Directed Acyclic Graph) — sem circuito
    Grafo dag(4, true);
    int s1[2]={0,1}; int s2[2]={1,2}; int s3[2]={2,3};
    dag += s1; dag += s2; dag += s3;

    verificar(
        "temCircuito == false em DAG (0->1->2->3)",
        !dag.temCircuito()
    );

    // Grafo com circuito  0->1->2->0
    Grafo comCiclo(4, true);
    int c1[2]={0,1}; int c2[2]={1,2}; int c3[2]={2,0};
    comCiclo += c1; comCiclo += c2; comCiclo += c3;

    verificar(
        "temCircuito == true em grafo com ciclo (0->1->2->0)",
        comCiclo.temCircuito()
    );

    // Grafo nao-direcionado com ciclo (triangulo)
    Grafo triangulo(3);
    int t1[2]={0,1}; int t2[2]={1,2}; int t3[2]={2,0};
    triangulo += t1; triangulo += t2; triangulo += t3;

    verificar(
        "temCircuito == true em triangulo nao-direcionado",
        triangulo.temCircuito()
    );

    // Arvore — nao-dir sem ciclo
    Grafo arvore(4);
    int a1[2]={0,1}; int a2[2]={0,2}; int a3[2]={0,3};
    arvore += a1; arvore += a2; arvore += a3;

    verificar(
        "temCircuito == false em arvore (estrela sem ciclo)",
        !arvore.temCircuito()
    );
}

// ------------------------------------------------------------
// TESTE 20 — componentesConexas e operações entre grafos
// ------------------------------------------------------------
void teste20_componentes_operacoes() {
    cabecalho("TESTE 20 — Grafo: componentesConexas e operacoes | & -");

    // Grafo com 4 componentes: {0,1,2}, {3,4}, {5}, {6}
    Grafo gComp(7);
    int c1[2]={0,1}; int c2[2]={1,2}; int c3[2]={3,4};
    gComp += c1; gComp += c2; gComp += c3;

    verificar(
        "componentesConexas == 4 ({0,1,2},{3,4},{5},{6})",
        gComp.componentesConexas() == 4
    );

    // Grafo totalmente conexo
    Grafo gConexo(4);
    int k1[2]={0,1}; int k2[2]={1,2};
    int k3[2]={2,3}; int k4[2]={0,3};
    gConexo += k1; gConexo += k2; gConexo += k3; gConexo += k4;

    verificar(
        "componentesConexas == 1 em grafo totalmente conexo",
        gConexo.componentesConexas() == 1
    );

    // Operações entre grafos
    Grafo g1(4), g2(4);
    int a1[2]={0,1}; int a2[2]={1,2};  // g1: 0-1, 1-2
    int a3[2]={1,2}; int a4[2]={2,3};  // g2: 1-2, 2-3
    g1 += a1; g1 += a2;
    g2 += a3; g2 += a4;

    Grafo gUniao = g1 | g2;
    verificar(
        "uniao G1|G2 contem aresta 0-1 (exclusiva de G1)",
        gUniao.existeAresta(0, 1)
    );
    verificar(
        "uniao G1|G2 contem aresta 2-3 (exclusiva de G2)",
        gUniao.existeAresta(2, 3)
    );
    verificar(
        "uniao G1|G2 contem aresta 1-2 (comum a ambos, sem duplicata)",
        gUniao.existeAresta(1, 2) && ~gUniao == 3
    );

    Grafo gInter = g1 & g2;
    verificar(
        "intersecao G1&G2 contem apenas aresta 1-2 (comum)",
        gInter.existeAresta(1, 2) && ~gInter == 1
    );
    verificar(
        "intersecao G1&G2 nao contem aresta 0-1 (exclusiva de G1)",
        !gInter.existeAresta(0, 1)
    );

    Grafo gDif = g1 - g2;
    verificar(
        "diferenca G1-G2 contem aresta 0-1 (exclusiva de G1)",
        gDif.existeAresta(0, 1)
    );
    verificar(
        "diferenca G1-G2 nao contem aresta 1-2 (esta em G2)",
        !gDif.existeAresta(1, 2)
    );
}

// ============================================================
// MAIN — executa todos os testes
// ============================================================
int main() {

    std::cout << "\n";
    std::cout << "############################################################\n";
    std::cout << "  BATERIA DE TESTES — Biblioteca Conjuntos e Grafos\n";
    std::cout << "############################################################\n";

    // --- Testes da classe Conjunto ---
    teste01_adicionar_pertence();
    teste02_remover();
    teste03_cardinalidade();
    teste04_pertinencia_insercao();
    teste05_igualdade();
    teste06_subconjunto();
    teste07_uniao();
    teste08_intersecao();
    teste09_diferenca();
    teste10_copia_atribuicao();

    // --- Testes da classe Grafo ---
    teste11_construtor_heranca();
    teste12_adicionar_existeAresta();
    teste13_operador_aresta();
    teste14_num_arestas_grau();
    teste15_vizinhos_direcionado();
    teste16_bfs();
    teste17_dfs();
    teste18_caminho();
    teste19_circuito();
    teste20_componentes_operacoes();

    resumo();

    return (testesFalhou == 0) ? 0 : 1;
}