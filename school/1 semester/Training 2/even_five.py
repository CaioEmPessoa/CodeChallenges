'''
Make a program that reads five integer values. Count how many of these values ​​are even and  print this information like the following example.
Input

The input will be 5 integer values.
Output

Print a message like the following example with all letters in lowercase, indicating how many even numbers were typed.
'''

numb_list = [input(), input(), input(), input(), input()]
even_ammount = 0

for numb in numb_list:
    numb = int(numb)
    if numb % 2==0:
        even_ammount+=1
    else:
        pass

print(str(even_ammount) + " valores pares")