'''
You must make a program that read a float-point number and print a message saying in which of following intervals the number belongs: [0,25] (25,50], (50,75], (75,100]. If the read number is less than zero or greather than 100, the program must print the message “Fora de intervalo” that means "Out of Interval".

The symbol '(' represents greather than. For example:
[0,25] indicates numbers between 0 and 25.0000, including both.
(25,50] indicates numbers greather than 25 (25.00001) up to 50.0000000.
Input

The input file contains a floating-point number.
Output

The output must be a message like following example.
'''

intervals = [[0,25], [25,50], [50,75], [75,100]]

numb = float(input())

if numb<0 or numb>100:
    print("Fora de intervalo")
    exit()

if numb > intervals[0][0] and numb < intervals[0][1]:
    print(f"Intervalo", intervals[0])

for interval in intervals[1:]:
    if numb > interval[0] and numb < interval[1]:
        print(f"Intervalo ({str(interval[0])},{str(interval[1])}]")