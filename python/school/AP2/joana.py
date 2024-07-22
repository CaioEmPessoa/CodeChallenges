data = input().split("/")
data = [int(valor) for valor in data]

if sum(data) % 2 == 0:
    print("par")
else:
    print("impar")
