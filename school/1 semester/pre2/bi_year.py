n1 = int(input())
n2 = int(input())

count = 0

for year in range(n1, n2 + 1):
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
        print(year)
        count += 1

print("bissextos:", count)
