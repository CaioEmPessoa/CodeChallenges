nota1 = float(input())
nota2 = float(input())

media = (nota1 + nota2) / 2
media_max = (nota1 + 10) / 2

if media >= 6 and media_max >= 6:
    print('aprovado')
elif media_max >= 6:
    print('talvez com a sub')
else:
    print('reprovado')

