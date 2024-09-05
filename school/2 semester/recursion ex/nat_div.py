list = []
def div(num1, num2):
    list.append(num1)

    if num1 < num2:
        return len(list)-1
    
    return div(num1 - num2, num2)

print(div(9, 3))