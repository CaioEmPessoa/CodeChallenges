

def counting_sort(lista):

   index = 0
   numb = [-1]
   final = lista[:]

   for i in lista:
      if i > index:
         for j in range(i - index):
            numb.append(0)

      numb[i] = numb[i] + 1
      
   for i in range(len(numb)-1):
      numb[i+1] = numb[i] + numb[i+1]

   for i in lista:
      final[numb[i]] = i
      numb[i] = numb[i]-1

   lista[:] = final
   return lista


lista = [2, 4, 0, 1, 9, 3, 3]
print(lista)
print(counting_sort(lista))
print(lista)
