# S = INICIO
# . = LIVRE
# E = INIMIGO (IGUAL PAREDE K)
# # = PAREDE
# G = FIM

LABIRINTO = [
    ["S", ".", "#", ".", ".", ".", "#", ".", "G"],
    [".", "#", ".", "#", ".", "#", ".", "#", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", "#", ".", "#", ".", "#", ".", "#", "."],
    [".", ".", ".", ".", "E", ".", ".", ".", "."],
    [".", "#", ".", "#", ".", "#", ".", "#", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
    [".", "#", ".", "#", ".", "#", ".", "#", "."],
    [".", ".", ".", ".", ".", ".", ".", ".", "."],
]


lab = LABIRINTO

# Gerar movimentos válidos a partir de uma posicao
def check_valid(pos):
    valid_blocks = []

    x_size = len(lab[0])
    y_size = len(lab)

    x, y = pos

    around = [
        (x  , y+1), # cima
        (x+1, y  ), # direita
        (x  , y-1), # baixo
        (x-1, y  ), # esquerda
        ]

    for valid_x, valid_y in around:
        if 0 <= valid_x <= x_size-1 and 0 <= valid_y <= y_size-1:
            check_block = lab[valid_x][valid_y]
            if check_block not in ["#", "E"]:
                valid_blocks.append((valid_x, valid_y))

    return valid_blocks

# Distancia de manhatan entre dois pontos
def manhatan_distance(pos1, pos2):
    x1, y1 = pos1
    x2, y2 = pos2
    m = abs(x1 - y1) + abs(x2 - y2)
    return m

# ======= ALGORITIMOS DE BUSCA =======
# bfs
def bfs(lab, start, end):

    buscando = True
    current = start
    buscados = [current]
    opcoes = []

    while buscando:
        x, y = current
        LABIRINTO[x][y] = "X"
        
        print(current)

        if current == end:
            LABIRINTO[x][y] = "!!"
            buscando = False
            return "encontrado!"

        for i in check_valid(current):
            if i not in buscados:
                opcoes.append(i) 

        if not opcoes:
            return "Nenhum caminho encontrado."

        for block in opcoes:
            if block not in buscados:
                current = block
                buscados.append(current)
                opcoes.remove(current)
            else:
                pass

    # explorar todas casas adjascentes antes de explorar um nivel a +
    return

print(
    bfs(lab, (0, 0), (6, 1))
)

print('---------')
print(LABIRINTO[0][5])
for i in LABIRINTO:
    print(i)
print('---------')

# dfs
def dfs():
    # explorar um caminho ate o fim.
    return

# Busca Gulosa

# Minimax


# ======= FUNCOES DE TESTE =======
# Testar cada algortimo com diferentes configs do labirinto

# Comparar o desempenho dos algoritimos em termo de passos, tempo de execucao e eficiencia de evitar inimigos


# ======= VISUALIZACAO =======
# Imprimir o labirinto no console

# Exibir o caminho encontrado por cada algoritimo