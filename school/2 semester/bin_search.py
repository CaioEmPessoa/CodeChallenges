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


def check_ord(self, lista):
    v = lista[0]
    for i in lista:
        if i > v:
            return False
        v = i

def bin_search(g_info:dict, value:int, minmax:tuple=False) -> int:
    # so the first call don't need to specify size of list
    if minmax == False:
        minmax = (0, len(g_info)-1)
    
    print(g_info)

    g_list = [g_info[r] for r in g_info]
    s_list = [r for r in g_info]
    min, max = minmax

    tam = min - max

    if value == g_list[tam//2]:
        return value, tam//2
    
    elif value > g_list[tam//2]:
        return bin_search(s_list[tam//2], value, (tam//2, max))
    
    elif value < g_list[tam//2]:
        return bin_search(s_list[tam//2], value, (min, tam//2))