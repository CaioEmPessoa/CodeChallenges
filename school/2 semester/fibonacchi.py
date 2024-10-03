from functools import lru_cache

def fib_rec(num, c=0):
    if num <= 1:
        return num, c+1
    else:
        fib1 = fib_rec(num-1)
        fib2 = fib_rec(num-2)
        return fib1[0]+fib2[0], fib1[1] + fib2[1]

def fib_loop(num):
    fib_l = [0, 1]
    c=0
    for x in range(num-1):
        fib = fib_l[1] + fib_l[0]
        fib_l[0], fib_l[1] = fib_l[1], fib
        c += 1
    return fib, c

print(fib_rec(5))
print(fib_loop(5))