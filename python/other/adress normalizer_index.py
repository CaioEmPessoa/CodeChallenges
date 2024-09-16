
class Normalize():

    def remove_chars(self, adress_name, number):

        if "," in number[-1]:
            number = number[:-1]

        if " " in number[0]:
            number = number[1:]
        if " " in number[-1]:
            number = number[:-1]
        
        if " " in adress_name[0]:
            adress_name = adress_name[1:]
        if " " in adress_name[-1]:
            adress_name = adress_name[:-1]

        return adress_name, number

    def adress(self, adress:str):
        name_first = True

        if " No " in adress:
            split_num = adress.index(" No ")
        elif adress[0].isdigit():
            split_num = len(adress.split(" ")[0])
            name_first = False
        else:
            split_adress = adress.split(" ")

            if split_adress[-1].isdigit():
                split_num = -len(split_adress[-1])
            
            elif split_adress[-2].isdigit():
                split_num = adress.index(split_adress[-2])
            else:
                return "Nenhum número foi encontrado para o endereço!"
            
        # returns adress correct order
        if name_first:
            adress_name = adress[:split_num]
            number = adress[split_num:]
        else:
            adress_name = adress[split_num:]
            number = adress[:split_num]

        adress_name, number = self.remove_chars(adress_name, number)
        
        return [adress_name, number]


if __name__ == "__main__":
    normalize = Normalize()
    print(normalize.adress("Calle 44 No 1991"))
    print(normalize.adress("100 Broadway Av"))
    print(normalize.adress("4, Rue de la République"))
    print(normalize.adress("Miritiba 339"))
    print(normalize.adress("Rio Branco 23"))
    print(normalize.adress("Quirino dos Santos 23 b"))