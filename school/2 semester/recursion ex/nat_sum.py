def soma_nat(numb:int):
    if numb == 1 : return 1
    return numb+soma_nat(numb-1)

print(soma_nat(3))