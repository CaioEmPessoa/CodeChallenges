
class Normalize():

    def address(self, adress:str) -> list[str]:

        # With NO
        if " No " in adress:
            split_num = adress.index(" No ")
            adress_name = adress[:split_num]
            number = adress[split_num+1:]

        # Numero no começo
        elif adress[0].isdigit():
            split_num = len(adress.split(" ")[0])
            number = adress[:split_num]
            adress_name = adress[split_num+1:]
            
            # Número com virgula
            if number[-1] == ",":
                number = number[:-1]

        # Número no final ou número junto de bloco
        # adicionado o split >= 2 por que retornaria erro caso contrário
        elif len(adress.split(" ")) >= 2 and (adress.split(" ")[-1].isdigit() or adress.split(" ")[-1][0].isdigit()):
            split_num = -len(adress.split(" ")[-1])
            adress_name = adress[:split_num-1]
            number = adress[split_num:]

        # Número e Bloco separados por espaço
        elif len(adress.split(" ")) >= 3 and adress.split(" ")[-2].isdigit():
            split_num = adress.index(adress.split(" ")[-2])
            adress_name = adress[:split_num-1]
            number = adress[split_num:]

        else:
            return "Nenhum número foi encontrado para o endereço!"

        return [adress_name, number]


if __name__ == "__main__":
    normalize = Normalize()
    entry = ""
    
    print("\n")
    print("Olá! Digite um endereço para ser normalizado ou \"teste\" para ver os casos de teste.")
    print("\"sair\" para sair.")

    while entry != "sair":
        entry = input("> ")
        
        if entry == "sair":
            break

        elif entry == "teste":
            addresses = [
                "Miritiba 339", "Cambuí 804B", "Rio Branco 23",
                "Quirino dos Santos 23 b", "Calle 44 No 1991",
                "100 Broadway Av", "4, Rue de la République"
            ]
            
            for address in addresses:
                print(f"Endereço: {address}")
                print(f"Separado: {normalize.address(address)}\n")

        else:
            address = entry
            print(f"Endereço: {address}")
            print(f"Separado: {normalize.address(address)}\n")
