def div(num1, num2):
    try:
        count += 1
    except:
        count = 0

    if num1 < num2:
        return count
    
    print(num1)

    return div(num1 - num2, num2)

print(div(6, 3))