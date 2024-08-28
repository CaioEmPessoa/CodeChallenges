valores_luiz = input().split(" ")

disposto = float(valores_luiz[0])
meses = int(valores_luiz[1])
dinheiro = float(valores_luiz[2])

valor_corretora = input().split(" ")

valor_minimo = float(valor_corretora[0])
meses_minimo = int(valor_corretora[1])
porcentagem = float(valor_corretora[2])

lucro_final = (disposto * (porcentagem/100)) + disposto

if disposto < valor_minimo or meses < meses_minimo or dinheiro > lucro_final:
    print("nao invista!")
else:
    print("invista!")    