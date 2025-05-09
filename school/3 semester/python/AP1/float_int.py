

def float_para_int(lista):
   lista[:] = [i*1.00 for i in lista]
   return lista

def int_para_float(lista):
   lista[:] = [i//1 for i in lista]
   return lista

lista = [1.0, 5., 10., 12.2, 54.3]
print(lista)
print(float_para_int(lista))
print(int_para_float(lista))
