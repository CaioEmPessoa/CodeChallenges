

def insertion_sort(lista):
   
   for j in range(len(lista)):
      at = lista[j] # atual
      final = j
      
      for i in range(j-1, -1, -1):
         ant = lista[i] # anterior
         if at < ant:
            lista[i+1] = lista[i]
            final = i
         else:
            break
      lista[final] = at

   return lista

lista = [3, 4, 1, 7, 2, 9, 0, 8]

print(lista)
print(sorted(lista))