## FUNCOES CONVENINETES DO PYTHON REFEITAS POR *MIM*
def rm_index(lista, item) -> list:
   lista[:] = lista[:item] + lista[item+1:]
   return lista

def absolute(item) -> int:
   return int((item**2)**0.5)

def volta_index(lista, item) -> int:
   i = len(lista)-1
   while i >= 0:
      if lista[i] == item:
         return i
      i -= 1

def diff_itens(lista:list, item:any): # confere a diferença entre todos itens de um array
   valor_diff = 0
   for i in lista:
      if i != item:
         valor_diff += absolute(item - i)

   return valor_diff

def calc_menor_custo(cortes:list, ultimo_corte:int, tam:int) -> tuple:
   menor_custo = L*2 # valor acima do limite
   menor_item = cortes[0]
   lista_cortada = []

   for i in cortes:
      atual_custo = diff_itens(lista=cortes, item=i)
      if atual_custo <= menor_custo:
         menor_custo = atual_custo
         menor_item = i

   corte = volta_index(cortes, menor_item)
   lista_cortada = rm_index(cortes, corte)

   valor = (tam - ultimo_corte)*10
   ultimo_corte = (menor_item - ultimo_corte) - (tam - ultimo_corte)

   if len(lista_cortada) <= 0: return menor_item, [], valor
   else: return menor_item, lista_cortada, valor

def cortes_tora(cortes:list, tam:int, custo:int):
   corte = 0
   ultimo_corte = 0
   tora = list(range(tam))
   valor_total = 0

   while len(cortes) > 0:
      corte += 1

      menor_item, cortes[:], valor = calc_menor_custo(cortes, ultimo_corte, tam)
      valor_total+=valor
      if corte % 2 != 0:
         ultimo_corte = menor_item
   return valor_total


R = 10 # Custo por metro de tora a ser cortada
L = 8 # Tamanho total da tora
cortes = [1, 4, 6]

menor_custo = cortes_tora(cortes, L, R)

print(f'Menor custo para os cortes = R$ {menor_custo}')

# NÃO MODIFIQUE ESSA CÉLULA

# Teste-1 da função cortes_tora()
random.seed(42)
N = 5
L = 10
cortes = sorted(random.sample(range(1, L), N))
R = 15

menor_custo = cortes_tora(cortes, L, R)
print(f'Menor custo para os cortes = R$ {menor_custo}')