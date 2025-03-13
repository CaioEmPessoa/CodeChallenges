
def bubble_sort(lista):

   for i in range(len(lista)):

      for j in range(0, len(lista)-i-1):

         if lista[j] > lista[j+1]:
            lista[j], lista[j+1] = lista[j+1], lista[j]

   return lista

def bucket_sort(lista):
   index = 0
   buckets = [[]]
   final = []

   for i in lista:
      tam = int(i / 30)
      
      if tam > index:
         for j in range(tam - index):
               buckets.append([])
         index = tam
         
      buckets[tam].append(i)

   for i in buckets:
      i = bubble_sort(i)
      
      for j in range(len(i)):
         final.append(i[j])
   
   lista[:] = final
   return lista 

lista = [3, 4, 1, 7, 2, 9, 0, 8]
print(lista)
print(bucket_sort(lista))