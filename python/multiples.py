'''
Read two integer values (A and B). After, the program should print the message "Sao Multiplos" (are multiples) or "Nao sao Multiplos" (aren’t multiples), corresponding to the read values.
Input

The input has two integer numbers.
Output

Print the relative message to the input as stated above.
'''

numbs = sorted(input().split(" "))

if int(numbs[0]) % int(numbs[1]) == 0:
    print("Sao Multiplos")
else:
    print("Nao sao Multiplos")

'''
# THIS CODE WAS THE ONLY ONE THAT WORKED
# EVEN THO THE FIRST ONE WAS CORRECT.
numbs = input().split(" ")
num1 = int(numbs[0])
num2 = int(numbs[1])

if num1 > num2:
    if num1 % num2 == 0:
        print("Sao Multiplos")
    else:
        print("Nao sao Multiplos")
else:
    if num2 % num1 == 0:
        print("Sao Multiplos")
    else:
        print("Nao sao Multiplos")

'''