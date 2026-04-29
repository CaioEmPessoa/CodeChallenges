import math

valores_str = "450; 468; 476; 480; 482; 485; 488; 490; 492; 494; 496; 498; 499; 501; 502; 504; 505; 506; 507; 508; 509; 510; 510; 511; 512; 513; 514; 515; 515; 516; 517; 518; 519; 520; 520; 521; 522; 523; 524; 524; 525; 525; 526; 527; 528; 529; 530; 530; 531; 532; 533; 534; 535; 535; 536; 537; 538; 539; 540; 540; 541; 542; 544; 545; 546; 548; 549; 550; 552; 554; 556; 558; 560; 562; 565; 568; 570; 574; 582; 600"

valores = [int(e) for e in valores_str.split("; ")]

# Amplitude total
amplitude_total = max(valores) - min(valores)

print(f"amplitude total: {amplitude_total}")

sturges = 1 + math.ceil(3.3 * math.log10(len(valores)))

numero_ideal_classes = amplitude_total / sturges

'''
{
    fr_abs: x,
    fr_rlt: x,
    fr_cml: x
}
'''
results = []

c_old = valores[0]
intervals = [c_old+( numero_ideal_classes*i ) for i in range(sturges+1)]
for v in range(len(intervals)):
    i     = intervals[v]
    i_old = intervals[v-1]
    
    c = min(valores, key=lambda x:abs(c_old+sturges))
    
    abslt = len([j for j in valores if j>=i_old and j < i])
    rltv  = abslt/sum(valores)
    acmld = sum([i["fr_abs"] for i in results])
    c_old = c

    results.append({
        "fr_abs": abslt,
        "fr_rlt": rltv,
        "fr_cml": acmld
    })

print(f"sturges - numero ideal de classes: {sturges}")
print(f"sturges - intervalo de classes: {numero_ideal_classes}")

for i in results:
    print(i)