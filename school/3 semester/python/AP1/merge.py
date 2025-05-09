def merge(left, right):
   middle = []
   i = 0
   j = 0

   while i < len(left) and j < len(right):
      if left[i] < right[j]:
         middle.append(left[i])
         i += 1
      else:
         middle.append(right[j])
         j += 1

   while i < len(left):
      middle.append(left[i])
      i += 1

   while j < len(right):
      middle.append(right[j])
      j += 1

   return middle

def merge_recurs(lista):
   tam = len(lista)
   if tam <= 1:
      return lista

   smaller = lista[0 : tam//2]
   bigger = lista[tam//2 : tam]

   return merge(merge_recurs(smaller), merge_recurs(bigger))

def merge_sort(lista: list) -> list:
   sorted_list = merge_recurs(lista)
   lista[:] = sorted_list
   return lista


lista = [2, 4, 0, 1, 9, 3, 3]
print(lista)
print(merge_sort(lista))
print(lista)
