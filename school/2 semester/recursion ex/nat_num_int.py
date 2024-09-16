def funcao(x):
    if x%2==0: return x/2
    
    return  3*x+1

def num_it(n):
    if funcao(n)==1: return 1
    
    return 1+num_it(funcao(n))

