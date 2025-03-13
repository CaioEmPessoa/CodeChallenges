

def selection_sort(lista):
   
   for i in range(len(lista)):
      min = i
      old = lista[i]

      for j in range(len(lista)-1, i, -1):
         if lista[j] < lista[min]:
            min = j

      old = lista[i]
      lista[i], lista[min] = lista[min], old
      
   return lista

lista = [0, 9, 2, 1, 3, 4]
print(lista)
print(selection_sort(lista))