from random import choice, randint

with open("numb.txt", "r") as x:
    numb = int(x.read())

SIZES = [3, 4, 5]

rand_size = choice(SIZES)

itens = [["||:hatching_chick:||" for i in range(rand_size)] for i in range(rand_size)]

itens[randint(0, rand_size-1)][randint(0, rand_size-1)] = "||:frog:||"

final_string = f"Encontre o Sapo #{numb}! Muda todo dia! (+/-)\n"

for i in itens:
    final_string += "".join(i) + "\n"

print(final_string)

with open("numb.txt", "w") as x:
    x.write(str(numb+1))

input()