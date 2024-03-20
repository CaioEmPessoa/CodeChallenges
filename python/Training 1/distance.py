'''
Read the four values corresponding to the x and y axes of two points in the plane, p1 (x1, y1) and p2 (x2, y2) and calculate the distance between them, showing four decimal places after the comma, according to the formula:

Distance = √(x2-x1)² + (y2-y1)²

Input
The input file contains two lines of data. The first one contains two double values: x1 y1 and the second one also contains two double values with one digit after the decimal point: x2 y2.

Output
Calculate and print the distance value using the provided formula, with 4 digits after the decimal point.
'''

from math import sqrt

x1, y1 = map(float, input().split(" "))
x2, y2 = map(float, input().split(" "))

distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2))
print(f"{distance:.4f}")