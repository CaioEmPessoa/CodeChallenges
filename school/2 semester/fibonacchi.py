from functools import lru_cache

def fib(num):
    if num <= 1:
        return 0
    elif num == 2:
        return 1
    else:
        return fib(num-1)+fib(num-2)
        
print("oi")
print(fib(500))
print(fib(100))
print(fib(500))