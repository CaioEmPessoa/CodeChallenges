import math

valores_str = """450; 468; 476; 480; 482; 485; 488; 490; 492; 494; 496; 498; 499; 501; 502; 504; 505; 506; 507; 508; 509; 510; 510; 511; 512; 513; 514; 515; 515; 516; 517; 518; 519; 520;520; 521; 522; 523; 524; 524; 525; 525; 526; 527; 528; 529; 530; 530; 531; 532; 533;534; 535; 535; 536; 537; 538; 539; 540; 540; 541; 542; 544; 545; 546; 548; 549; 550;552; 554; 556; 558; 560; 562; 565; 568; 570; 574; 582; 600"""

valores = [int(e) for e in valores_str.split(";")]

# nao faço ideia kk apenas saiba que ele desocbre a quantidade de classes que um intervalo precisa
# pra ser dividido igualmente em algumas partes ai
sturges = round(1 + 3.3 * math.log10(len(valores)))

# Amplitude (diferença do maior pro menor) de TODOS valores
amplitude_total = math.ceil(max(valores) - min(valores))

# Média de amplitudes por classes. Utiliza o valor de sturges pra fazer este cálculo
amplitude_classe = math.ceil(amplitude_total/sturges)

# Variaveis pra logica do if abaixo
results = []
acmld = 0

for v in range(sturges):
    # Intervalo, definido pelo menor valor do "valores" + a amplitude da classe * o index da classe atual
        # em resumo, cada classe é esperada ter uma quantidade pré-definida de itens dentro do range dela,
        # e este range é a amplitude * a classe atual
    i_inf = min(valores) + v * amplitude_classe         # limite inferior
    i_sup = min(valores) + (v + 1) * amplitude_classe   # limite superior

    # Apenas a quantidade de itens dentro do intervalo definido acima
    if v == sturges - 1: # muda o comportamento quando é o ULTIMO item da lista
        abslt = len([i for i in valores if i >= i_inf and i <= i_sup])
    else:
        abslt = len([i for i in valores if i >= i_inf and i < i_sup])

    rltv  = abslt / len(valores) # Quantidade de itens / pelo total
    acmld += abslt # apenas soma todos valores absolutos de vez em vez

    results.append({
        "interval": f"{i_inf} - {i_sup}",
        "fr_abs": abslt,
        "fr_rlt": round(rltv, 4)*100,
        "fr_cml": acmld
    })

print(valores)
print("=====-----=====")
print(f"amplitude total: {amplitude_total}")
print(f"sturges - numero ideal de classes: {sturges}")
print(f"sturges - intervalo das classes: {amplitude_classe}")

print(f"{'Intervalo':<10} {'Fi':>6} {'fr':>8} {'Fac':>6}")
for i in results:
        print(f"{i['interval']:<10} {i['fr_abs']:>6} {i['fr_rlt']:>8.2f} {i['fr_cml']:>6}")