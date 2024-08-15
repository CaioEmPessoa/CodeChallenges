import os

palavra = input("Escolha uma palavra: (quem for jogar não olha)\n")

os.system('cls')

print("Agora tentem adivihar a palavra!")

palavra = [l for l in palavra]
adivinha = ["_" for l in palavra]
total_chute = []

while adivinha != palavra:
    i = 0
    os.system('cls')
    
    print(total_chute)
    print(" ".join(adivinha))
    
    chute = input("Chute uma letra! ")
    if len(chute) > 1:
        print("Apenas uma letra! ")
        continue
    
    for l in palavra:
        if l == chute:
            adivinha[i] = chute
        if chute not in total_chute:
            total_chute.append(chute)
            total_chute.sort()
        i += 1
    

print(f"parabéns! acertou a palavra '{"".join(adivinha)}' !")