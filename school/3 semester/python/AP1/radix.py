
def get_digit(number, digit_index):
   return (number // (10 ** digit_index)) % 10

def count_max_digits_list(lista):
   max_n = lista[0]
   max_digits = 0
   for i in lista:
      if i > max_n:
         max_n = i

   temp = max_n
   while temp > 0:
      temp //= 10
      max_digits += 1

   return max_digits

def radix_sort(lista):
   max_digits = count_max_digits_list(lista)
   lista_aux = lista[:]

   for i in range(max_digits):
      digits = [[] for _ in range(10)]
      for num in lista_aux:
         digit = get_digit(num, i)
         digits[digit].append(num)
      
      lista_aux = [num for sublist in digits for num in sublist]

   lista[:] = lista_aux
   return lista

lista = [2, 4, 0, 10, 9, 3, 3]
print(lista)
print(radix_sort(lista))
print(lista)
