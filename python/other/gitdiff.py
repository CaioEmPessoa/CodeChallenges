## Code that replicates the diff on files made by github

import os
import time
from tkinter import filedialog

print("Qual diretório quer abrir?")
DIR = filedialog.askdirectory()

acompanhar = True

listaAtual = set(os.listdir(DIR))
listaOriginal = listaAtual

print("------ ARQUIVOS ORIGINAIS ------")
for i in listaOriginal:
    print(">"+i)
print("--------------------------------")

while acompanhar:
    # print("checando...")

    listaOriginal = listaAtual
    listaAtual = set(os.listdir(DIR))
    
    if listaOriginal != listaAtual:
        print("----- ARQUIVOS MODIFICADOS -----")
        for i in listaAtual | listaOriginal:
            if i not in listaOriginal:
                print("+" + i)
            elif i not in listaAtual:
                print("-" + i)
            else:
                print(">" + i)

        print("--------------------------------")
    
    time.sleep(1)