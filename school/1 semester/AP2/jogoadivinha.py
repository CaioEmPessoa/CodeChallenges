jogadas = int(input())

jogadores = {"megan":0,
             "tom":0}

for jogada in range(jogadas):
    pergunta = input().split(" ")

    nome = pergunta[0]

    num1 = pergunta[1]
    op = pergunta[2]
    num2 = pergunta[3]

    resposta_c = eval(num1+op+num2)
    
    resposta_t = float(input())

    if resposta_t == resposta_c:
        jogadores[nome] += 1
    elif resposta_t != resposta_c:
        jogadores[nome] -= 1

print(f"megan = {jogadores['tom']}\ntom = {jogadores['megan']}")

if jogadores['tom'] > jogadores['megan']:
    esperto = "megan"
elif jogadores['megan'] > jogadores['tom']:
    esperto = "tom"

print(f"mais esperto = {esperto}")

