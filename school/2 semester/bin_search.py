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