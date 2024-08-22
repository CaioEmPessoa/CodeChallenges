import random
import pprint

def gerar_cpf():
    return str(round(random.random()*1000000000))

cpfs = {gerar_cpf() for i in range(100)}

def gerar_subconjunto(conjunto):
    return set(random.sample(list(conjunto), int(random.random() * len(conjunto))))

esportes = {
    "judo": {},
    "surf": {},
    "vôlei": {},
    "ginastica": {}
}

for esporte in esportes:
    esportes[esporte] = gerar_subconjunto(cpfs)
    print(f"{esporte}: {len(esportes[esporte])}")

aparece_em_dois = []

for cpf in cpfs:
    aparece_em = 0
    for esporte in esportes:
        if cpf in esportes[esporte]:
            aparece_em += 1
    if aparece_em >= 2:
        aparece_em_dois.append(cpf)

"""
pares = [
    esportes['judo'] & esportes['surf'],
    esportes['judo'] & esportes['vôlei'],
    esportes['judo'] & esportes['ginastica'],
    esportes['surf'] & esportes['vôlei'],
    esportes['surf'] & esportes['ginastica'],
    esportes['vôlei'] & esportes['ginastica'],
]

aparece_em_dois_dois = []

for cpf in cpfs:
    for par in pares:
        if cpf in par:
            aparece_em_dois_dois.append(cpf)
            break
            
print(len(aparece_em_dois_dois))
"""

print(f"Judo ou surf: {len(esportes["judo"] | esportes["surf"])}%")
print(f"Pelo menos dois: {len(aparece_em_dois)}%")
print(f"Todos os esportes: {len(esportes['ginastica'] & esportes['surf'] & esportes['vôlei'] & esportes['judo'])}%")
print(f"Nenhum esporte: {len(cpfs - esportes['ginastica'] & esportes['surf'] & esportes['vôlei'] & esportes['judo'])}%")