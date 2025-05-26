import random

coisas = []
print("escreve alguma coisa ai doug kk")
while True:
    coisa = input("> ")
    if coisa == "":
        break
    coisas.append(coisa)


def escolher_coisas():
    escolha = random.choice(coisas)
    print(escolha, "\n")

    ctz = input("")

    if ctz == "":
        escolher_coisas()

escolher_coisas()
