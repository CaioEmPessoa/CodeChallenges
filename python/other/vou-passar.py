import numpy as np
import matplotlib.pyplot as plt

def ss():

    print()
    AP1 = float(input("Qual sua nota da primeira ap?\n> "))
    AP2_valores = np.linspace(0, 10, 100)

    PR_valores = (12-(AP1*0.5)) - 0.5 * AP2_valores

    area_estasafedog = (PR_valores >= 0) & (PR_valores <= 10)

    plt.figure(figsize=(10, 6))
    plt.plot(AP2_valores[area_estasafedog], PR_valores[area_estasafedog], label=f'PR = {12-(AP1*0.5)} - 0.5 * AP2', color='blue')
    plt.fill_between(AP2_valores[area_estasafedog], PR_valores[area_estasafedog], 10, color='lightblue', alpha=0.5)


    plt.xlim(0, 10)
    plt.ylim(0, 10)

    plt.xticks(np.arange(0, 10.5, 0.5))
    plt.yticks(np.arange(0, 10.5, 0.5))

    plt.title('Notas da PR e AP2')
    plt.xlabel('AP2')
    plt.ylabel('PR')
    plt.axhline(y=10, color='red', linestyle='--', label='PR Limite')
    plt.axvline(x=10, color='red', linestyle='--', label='AP2 Limite')

    plt.legend()

    plt.grid()
    plt.show()

ss()

while True:
    s = input("outra nota?")
    if s == "n":
        exit()
    ss()