'''
Leia 2 valores inteiros X e Y. A seguir, calcule e mostre a soma dos números impares entre eles.
Entrada

O arquivo de entrada contém dois valores inteiros.
Saída

O programa deve imprimir um valor inteiro. Este valor é a soma dos valores ímpares que estão entre os valores fornecidos na entrada que deverá caber em um inteiro.
'''

num_list = [int(input()), int(input())]
num_list.sort()

odd_total_sum = 0

for i in range(num_list[0]+1, num_list[1]):
    if i%2!=0:
        odd_total_sum += i

print(odd_total_sum)

