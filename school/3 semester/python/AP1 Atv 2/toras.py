def quick_sort(lista):
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

   return quick_sort(smaller) + equal + quick_sort(bigger)

def menor(item1, item2):
   return item1 if item1 < item2 else item2

def cortes_tora(cortes, tam, custo):
   cortes = [0] + quick_sort(cortes) + [tam]
   qnt_cortes = len(cortes)
   
   custos = [[0] * qnt_cortes for _ in range(qnt_cortes)]
   
   for tamanho in range(2, qnt_cortes):
      for inicio in range(qnt_cortes - tamanho):
         fim = inicio + tamanho 
         custos[inicio][fim] = tam**99
         for corte_meio in range(inicio + 1, fim):
               custo_final = custos[inicio][corte_meio] + custos[corte_meio][fim] + (cortes[fim] - cortes[inicio]) * custo
               custos[inicio][fim] = menor(custos[inicio][fim], custo_final)
   
   return custos[0][qnt_cortes-1]