'''
Leia 100 valores inteiros. Apresente então o maior valor lido e a posição dentre os 100 valores lidos.
Entrada

O arquivo de entrada contém 100 números inteiros, positivos e distintos.
Saída

Apresente o maior valor lido e a posição de entrada, conforme exemplo abaixo.
'''

num_list = []
for i in range(100):
    num_list.append(int(input()))

big = max(num_list)
pos = num_list.index(big)

print(big)
print(pos+1)