def quick_recurs(lista):
   if len(lista) <= 1:
      return lista

   pivot = lista[len(lista) // 2]
   smaller = []
   equal = []
   bigger = []

   for i in lista:
      if i < pivot:
         smaller.append(i)
      elif i == pivot:
         equal.append(i)
      else:
         bigger.append(i)

   return quick_recurs(smaller) + equal + quick_recurs(bigger)

def quick_sort(lista: list) -> list:
   sorted_list = quick_recurs(lista)
   lista[:] = sorted_list
   return lista

lista = [2, 4, 0, 1, 9, 3, 3]
print(lista)
print(quick_sort(lista))
print(lista)
