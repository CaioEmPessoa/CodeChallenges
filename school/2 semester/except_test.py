lista = []
user = 0

while user != -1:
    user = input("Insira valor: \n> ")
    try:
        float(user)
    except:
        print("Valor não inteiro inserido.")
        continue
    if user == int(-1):
        break
    print(user)
    lista.append(user)

if len(lista) > 10:
    raise IndexError("Lista com mais valores do que deveria")