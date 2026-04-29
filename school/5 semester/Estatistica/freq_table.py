import math

valores_str = """
1,80; 1,83; 1,85; 1,86; 1,86; 1,87; 1,87; 1,87; 1,88; 1,88; 1,88; 1,89; 1,89; 1,90; 1,90;
1,90; 1,90; 1,91; 1,91; 1,91; 1,91; 1,91; 1,92; 1,92; 1,92; 1,92; 1,92; 1,92; 1,93; 1,93;
1,93; 1,93; 1,93; 1,93; 1,94; 1,94; 1,94; 1,94; 1,94; 1,94; 1,95; 1,95; 1,95; 1,95; 1,95;
1,95; 1,96; 1,96; 1,96; 1,96; 1,96; 1,96; 1,97; 1,97; 1,97; 1,97; 1,97; 1,97; 1,98; 1,98;
1,98; 1,98; 1,98; 1,99; 1,99; 1,99; 1,99; 2,00; 2,00; 2,01; 2,01; 2,01; 2,02; 2,02; 2,02;
2,03; 2,03; 2,04; 2,06; 2,10
"""

valores_snt = valores_str.replace("\n", "").replace(",", ".")
valores_arr = valores_snt.split(";")

try:
    int(valores_arr[0])
    isfloat=False
except:
    try:
        float(valores_arr[0])
        isfloat = True
    except:
        print("Por favor, insira ou um array de int ou de float.")
        exit()

valores = [float(e) if isfloat else int(e) for e in valores_arr]

print(valores)

# Cálculo de Sturges corrigido: usa 3.322 e ceil em vez de 3.3 e round
sturges = math.ceil(1 + 3.322 * math.log10(len(valores)))

# Amplitude (diferença do maior pro menor) de TODOS valores
amplitude_total = round(max(valores) - min(valores), 2)

# Média de amplitudes por classes. Utiliza o valor de sturges pra fazer este cálculo
amplitude_classe = round(amplitude_total/sturges, 2)

print("==============-- RESPOSTAS---==============")

print(f"amplitude total: {amplitude_total}")
print(f"sturges - numero ideal de classes: {sturges}")
print(f"sturges - intervalo das classes: {amplitude_classe}")
print()
print()

print("==============-- CALCULOS---==============")
print("=====-- AMPLITUDE TOTAL --=====")
print(f"({max(valores)} - {min(valores)})")
print(amplitude_total)
print("==============-----==============")
print()

print("=====-- STURGES --=====")
print(f"1 + 3,322 * log10({len(valores)})")
print(f"1 + 3,221 * { round( math.log10(len(valores)), 2 ) }")
print(f"1 + {round( 3.221 * round( math.log10(len(valores)), 2 ), 2)}")
print(f" {sturges} *arredondado pra cima")
print("==============-----==============")
print()

print("=====-- AMPLITUDE CLASSES --=====")
print(f"{amplitude_total}/{sturges}")
print(f"{amplitude_classe} *arredondado pra duas casas")

print("==============-----==============")
print()
print()

# Variaveis pra logica do if abaixo
results = []
acmld = 0

for v in range(sturges):
    # Intervalo, definido pelo menor valor do "valores" + a amplitude da classe * o index da classe atual
        # em resumo, cada classe é esperada ter uma quantidade pré-definida de itens dentro do range dela,
        # e este range é a amplitude * a classe atual
    i_inf = round(min(valores) + v * amplitude_classe, 2)         # limite inferior
    i_sup = round(min(valores) + (v + 1) * amplitude_classe, 2)   # limite superior

    # Apenas a quantidade de itens dentro do intervalo definido acima
    if v == sturges - 1: # muda o comportamento quando é o ULTIMO item da lista
        abslt = len([i for i in valores if i >= i_inf and i <= i_sup])
    else:
        abslt = len([i for i in valores if i >= i_inf and i < i_sup])

    rltv  = abslt / len(valores) # Quantidade de itens / pelo total
    acmld += abslt # apenas soma todos valores absolutos de vez em vez

    results.append({
        "interval": f"{i_inf:.2f} - {i_sup:.2f}",
        "fr_abs": abslt,
        "fr_rlt": round(rltv, 4)*100,
        "fr_cml": acmld
    })

print(f"{'Intervalo':<20} {'Fi':>6} {'fr':>8} {'Fac':>6}")
for i in results:
        print(f"{i['interval']:<20} {i['fr_abs']:>6} {i['fr_rlt']:>8.2f} {i['fr_cml']:>6}")

print("=====-----=====")
