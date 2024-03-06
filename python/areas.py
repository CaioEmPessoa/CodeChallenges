'''
Make a program that reads three floating point values: A, B and C. Then, calculate and show:
a) the area of the rectangled triangle that has base A and height C.
b) the area of the radius's circle C. (pi = 3.14159)
c) the area of the trapezium which has A and B by base, and C by height.
d) the area of the square that has side B.
e) the area of the rectangle that has sides A and B.

Input
The input file contains three double values with one digit after the decimal point.

Output
The output file must contain 5 lines of data. Each line corresponds to one of the areas described above, always with a corresponding message (in Portuguese) and one space between the two points and the value. The value calculated must be presented with 3 digits after the decimal point.
'''

A, B, C = map(float, input().split(" "))

PI = 3.14159

formulas_dict = {
    "TRIANGULO": (A*C)/2,
    "CIRCULO":PI* C**2,
    "TRAPEZIO": (A+B) * C/2,
    "QUADRADO": B*B,
    "RETANGULO": A*B
}

for form in formulas_dict:
    print(f"{form}: {formulas_dict[form]:.3f}")