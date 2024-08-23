prod = {}

for i in range(5):
    name = input("Nome do produto: ")
    preco = int(input("Preco do produto: "))

    prod[name] = preco

for j in prod:
    if prod[j] > 50:
        print(f"{j} R${prod[j]}")