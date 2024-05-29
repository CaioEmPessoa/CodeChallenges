qnt_func = int(input())

data_func = {}

for i in range(qnt_func):
    new_func_data = input().split(' ')
    
    data_func.update({new_func_data[0]:{"bonificacao":float(new_func_data[1])}})


modificando = True
while(modificando):
    mod_func = input().split(' ')

    if mod_func[0] == "FIM":
        modificando = False
        break

    acao_fun = mod_func[0]
    valor_fun = float(mod_func[1])
    nome_fun = mod_func[2]

    if acao_fun == "reduz":
        try:
            data_func[nome_fun]["bonificacao"] -= valor_fun
            if data_func[nome_fun]["bonificacao"] < 0:
                data_func[nome_fun]["bonificacao"] = 0
        except:
            continue

    elif acao_fun == "aumenta":
        try:
            data_func[nome_fun]["bonificacao"] += valor_fun
        except:
            continue

for func in sorted(list(data_func)):
    print("Nome: " + func)
    print(f"Bonificacao: R$ {data_func[func]['bonificacao']:.2f}")
    print("--------------------")
