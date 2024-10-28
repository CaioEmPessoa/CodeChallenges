class BinSearch():
    def check_ord(self, lista):
        v = lista[0]
        for i in lista:
            if i < v:
                raise "Erro"
            v = i
    def search_value(self):
        pass


l1 = [1, 2, 3, 4, 5]
l2 = [2, 5, 1, 3, 6]

bin_search = BinSearch()
bin_search.check_ord(l2)


# def check_ord(self, lista):
#     v = lista[0]
#     for i in lista:
#         if i > v:
#             return False
#         v = i

# def bin_search(info:dict, value:int):
#     s_info_list = [info[r] for r in info] # r == register
#     if check_ord == False:
#         raise "Erro. Lista não ordenada."
    
#     tam = len(lista)

#     if value == lista[tam//2]:
#         return value, lista[tam//2]
#     else:
#         value, index = bin_search(lista[tam//2])
#         return value, index
