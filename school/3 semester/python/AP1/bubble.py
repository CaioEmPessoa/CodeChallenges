

def bubble_sort(lista):

   for i in range(len(lista)):
      
      for j in range(0, len(lista)-i-1):

         if lista[j] > lista[j+1]:
            lista[j], lista[j+1] = lista[j+1], lista[j]

   return lista
lista = [3, 4, 1, 7, 2, 9, 0, 8]

print(lista)
print(bubble_sort(lista))