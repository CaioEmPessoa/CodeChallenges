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


# Gerar movimentos válidos a partir de uma posicao
def check_valid(lab, pos):
    valid_blocks = []

    x_size = len(lab[0])
    y_size = len(lab)

    y, x = pos

    around = [
        (y-1, x  ), # cima
        (y  , x+1), # direita
        (y+1, x  ), # baixo
        (y  , x-1), # esquerda
        ]

    for valid_y, valid_x in around:
        if 0 <= valid_y < y_size and 0 <= valid_x < x_size:
            check_block = lab[valid_y][valid_x]
            if check_block not in ["#", "E"]:
                valid_blocks.append((valid_y, valid_x))

    return valid_blocks

# Distancia de manhatan entre dois pontos
def manhatan_distance(pos1, pos2):
    x1, y1 = pos1
    x2, y2 = pos2
    m = abs(x1 - y1) + abs(x2 - y2)
    return m

# ======= ALGORITIMOS DE BUSCA =======
# bfs
from collections import deque
def bfs(lab, start, end):

    buscados = set()
    opcoes = deque([(start, [start])])

    while opcoes:
        atual, path = opcoes.popleft()

        if atual == end:
            return path

        for i in check_valid(lab, atual):
            if i not in buscados:
                buscados.add(i)
                opcoes.append((i, path + [i]))

    return "Nenhum caminho encontrado."

print('---------')
for i in LABIRINTO:
    print(i)
print('---------')

print(
    "bfs: ",
    bfs(LABIRINTO, (0, 0), (0, 8))
)

# dfs
def dfs(lab, start, end):

    buscados = set([start])
    opcoes = [(start, [start])]

    while opcoes:
        current, path = opcoes.pop()

        if current == end:
            return path

        for i in check_valid(lab, current):
            if i not in buscados:
                buscados.add(i)
                opcoes.append((i, path + [i]))

    return "Nenhum caminho encontrado."

print(
    "dfs: ",
    dfs(LABIRINTO, (0, 0), (0, 8))
)

# Busca Gulosa

# Minimax


# ======= FUNCOES DE TESTE =======
# Testar cada algortimo com diferentes configs do labirinto

# Comparar o desempenho dos algoritimos em termo de passos, tempo de execucao e eficiencia de evitar inimigos


# ======= VISUALIZACAO =======
# Imprimir o labirinto no console
def exibir_lab(lab, width=1, hide_dot=False):
    for row in lab:
        print([col.rjust(width).replace(".", " " if hide_dot==True else ".") for col in row])

# Exibir o caminho encontrado por cada algoritimo
def exibir_caminho(lab:[], path:(int, int)):
    lab_path = lab.copy()

    num = 0

    for y, x in path:
        lab_path[y][x] = str(num)
        num+=1

    exibir_lab(lab=lab_path, width=2, hide_dot=True)

def performance(lab):
    arr = [
            dfs(LABIRINTO, (0, 0), (0, 8)),
            bfs(LABIRINTO, (0, 0), (0, 8))
        ]

    print(f"O melhor é: {max(arr)} passos!")
    #ou algo assim..
