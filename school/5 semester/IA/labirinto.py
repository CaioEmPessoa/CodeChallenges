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
    print("Checking", pos)
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
        if 0 <= valid_x <= x_size and 0 <= valid_y <= y_size:
            check_block = lab[valid_x][valid_y]
            if check_block not in ["#", "E"]:
                print(f"Valid: {valid_x}:{valid_y} '{check_block}'" )
                valid_blocks.append((valid_x, valid_y))

    return valid_blocks

# Distancia de manhatan entre dois pontos
def manhatan_distance(pos1, pos2):
    x1, y1 = pos1
    x2, y2 = pos2
    m = abs(x1 - y1) + abs(x2 - x2)
    return m

# ======= ALGORITIMOS DE BUSCA =======
# bfs
def bfs():
    # explorar todas casas adjascentes antes de explorar um nivel a +
    return

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