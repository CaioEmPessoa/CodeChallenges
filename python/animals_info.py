'''In this problem, your job is to read three Portuguese words. These words define an animal according to the table below, from left to right. After, print the chosen animal defined by these three words.'''

animals = {
    "vertebrado":{
        "ave":{
            "carnivoro":"aguia",
            "onivoro":"pomba"
        },
        "mamifero":{
            "onivoro":"homem",
            "herbivoro":"vaca"
        }
    },
    "invertebrado":{
        "inseto":{
            "hematofago":"pulga",
            "herbivoro":"lagarta"
        },
        "anelideo":{
            "hematofago":"sanguessuga",
            "onivoro":"minhoca"
        }        
    }
}

classe = input()
especie = input()
ossos = input()

print(animals[classe][especie][ossos])