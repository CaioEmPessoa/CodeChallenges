from functools import lru_cache
import matplotlib.pyplot as plt
from json import dumps

def fib_it(num):
    fib_it = [0, 1]
    c=0
    for x in range(num-1):
        fib = fib_it[1] + fib_it[0]
        fib_it[0], fib_it[1] = fib_it[1], fib
        c += 1
    return fib_it, c

def fib_rec(num, c=0):
    if num <= 1:
        return num, c+1
    else:
        fib1 = fib_rec(num-1)
        fib2 = fib_rec(num-2)
        return fib1[0]+fib2[0], fib1[1] + fib2[1]

cache = {}
def fib_rec_mem(num, c=0):
    if num in cache:
        return cache[num], c+1

    if num <= 1:
        cache[num] = num, c+1
        return num, c+1
    else:
        fib1 = fib_rec_mem(num-1)
        fib2 = fib_rec_mem(num-2)
        cache[num] = (fib1[0]+fib2[0], fib1[1] + fib2[1])
        return fib1[0]+fib2[0], fib1[1] + fib2[1]

data = {}

test_range = range(10)

for i in test_range:
    rec = fib_rec(i)
    rec_mem = fib_rec_mem(i)
    it = fib_it(i)

    data[i] = [it[1], rec[1], rec_mem[1]]

# print(dumps(data, indent=2))

plt.plot(test_range, [i[0] for i in data.values()], marker='o', label='Fib It', color="red")
plt.plot(test_range, [i[1] for i in data.values()], marker='o', label='Fib Rec', color="blue")
plt.plot(test_range, [i[2] for i in data.values()], marker='o', label='Fib Rec Mem', color="green", linestyle='--')

plt.xscale('linear')
plt.yscale('linear')

plt.xlabel('N-ésimo número.')
plt.ylabel('Quantidade de Passos')
plt.title('Análise do Cálculo de Fibonacchi')
plt.legend()
plt.grid(True)

plt.show()

