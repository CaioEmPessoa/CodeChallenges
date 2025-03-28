'''
    Corte de toras: considere uma tora de madeira de comprimento L (em metros -- m),
    a qual desejamos cortá-la N vezes em posições determinadas pela lista [p1,p2,p3,...,pN]. 
    Cada corte custa R reais por metro de tora a ser cortada, por exemplo se R=5 e L=10, 
    o valor do primeiro corte será R$ 50,00 independente do ponto de corte. 
    Determine o valor total mínimo para os N cortes.
    
    ## Basicamente dividir a madeira pela metade mais rapido possivel
'''

R = 10 # Custo por metro de tora a ser cortada
L = 8 # Tamanho total da tora
cortes = [1, 4, 6]

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

def menor_custo(cortes:list, ultimo_corte:int, tam:int) -> tuple:
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

   valor = tam - ultimo_corte
   ultimo_corte = (menor_item - ultimo_corte) - (tam - ultimo_corte)
   
   if len(lista_cortada) <= 0: return menor_item, [], valor
   else: return menor_item, lista_cortada, valor

def cortes_tora(cortes:list, tam:int, custo:int):
   corte = 0
   ultimo_corte = 0
   tora = list(range(tam))

   while len(cortes) > 0:
      print(cortes)
      corte += 1

      menor_item, cortes[:], valor = menor_custo(cortes, ultimo_corte, tam)
      if corte % 2 != 0:
         ultimo_corte = menor_item
      print(f"{corte} corte em {menor_item}m (R$ {valor*custo})")

      # try:
      #    cortes[0][0]
      #    for i in cortes:
      #       if len(i) <= 0: return
      #       menor_item, cortes[:], valor = menor_custo(i, ultimo_corte, tam)
      #       print(f"{corte} corte em {menor_item}m (R$ {valor*custo})")
            
      # except:
   
   


menor_custo = cortes_tora(cortes, L, R)

"1º corte em 4m (R$ 80)"
"2º corte em 1m (R$ 40)"
"3º corte em 6m (R$ 40)"

print(f'Menor custo para os cortes = R$ {menor_custo}')

"Menor custo para os cortes = R$ 160"