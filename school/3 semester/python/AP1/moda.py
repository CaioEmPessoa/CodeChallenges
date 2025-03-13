import numpy as np

def determina_moda(lista):
   qntItem = []

   qntItem.append([lista[0], 0])

   for i in range(len(lista)):
      item = lista[i]

      for j in range(len(qntItem)+1):
         if j == len(qntItem):
            qntItem.append([item, 1])
            break

         if item == qntItem[j][0]:
               qntItem[j][1] += 1
               break
   
   maior = qntItem[0]
   for i in qntItem:
      if i[1] >= maior[1]:
         maior = i

   return maior[0]

np.random.seed(0)
lista_teste_1 = (np.random.rand(100) * 50).astype(int).tolist()
lista_teste_2 = (np.random.randn(500) * 10).astype(int).tolist()
lista_teste_3 = (np.abs(np.random.randn(800)) * 5).astype(int).tolist()

print(determina_moda(lista_teste_1))
print(determina_moda(lista_teste_2))
print(determina_moda(lista_teste_3))