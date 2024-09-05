lista = []
def num_it(num):
    lista.append(" ")
    if num <= 1:
        return len(lista)
    if num%2==0:
        return num_it(num/2)
    else:
        return num_it((num*3)+1)

print(num_it(100))