import random
import pprint

# Generates a random id with size of 9 
def gerar_cpf():
    return str(round(random.random()*1000000000))

# Generate 100 random ids with size of 9
cpfs = {gerar_cpf() for i in range(100)}

# Choose between all of the numbers generated and return a random ammount of them. 
def gerar_subconjunto(conjunto):
    return set(random.sample(list(conjunto), int(random.random() * len(conjunto))))

esportes = {
    "judo": {},
    "surf": {},
    "vôlei": {},
    "ginastica": {}
}

# For each sport, adds a random ammount of ids to it.
for esporte in esportes:
    esportes[esporte] = gerar_subconjunto(cpfs)
    print(f"{esporte}: {len(esportes[esporte])}")

aparece_em_dois = []

# Search for ids in more than one sport
for cpf in cpfs:
    aparece_em = 0
    for esporte in esportes:
        if cpf in esportes[esporte]:
            aparece_em += 1
    if aparece_em >= 2:
        aparece_em_dois.append(cpf)

"""
# Lists all posible pairs in list of sports
pares =
    esportes['judo'] & esportes['surf'],
    esportes['judo'] & esportes['vôlei'],
    esportes['judo'] & esportes['ginastica'],
    esportes['surf'] & esportes['vôlei'],
    esportes['surf'] & esportes['ginastica'],
    esportes['vôlei'] & esportes['ginastica'],
]

aparece_em_dois_dois = []

# Search in it pair if it id appears more than one time
for cpf in cpfs:
    for par in pares:
        if cpf in par:
            aparece_em_dois_dois.append(cpf)
            break
            
print(len(aparece_em_dois_dois))
"""

# Concatenate all of sports pairs so that it only returns ids that are on more than one sport 
pares = (esportes['judo'] & esportes['surf']) | (esportes['judo'] & esportes['vôlei']) | (esportes['judo'] & esportes['ginastica']) | (esportes['surf'] & esportes['vôlei']) | (esportes['surf'] & esportes['ginastica']) | (esportes['vôlei'] & esportes['ginastica'])

# Prints all of it
print(f"Judo ou surf: {len(esportes["judo"] | esportes["surf"])}%")
print(f"Pelo menos dois: {len(aparece_em_dois)}%")
print(f"Pelo menos dois: {len(pares)}%")
print(f"Todos os esportes: {len(esportes['ginastica'] & esportes['surf'] & esportes['vôlei'] & esportes['judo'])}%")
print(f"Nenhum esporte: {len(cpfs - esportes['ginastica'] & esportes['surf'] & esportes['vôlei'] & esportes['judo'])}%")