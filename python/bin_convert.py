num_dec = int(input("Insert the decimal number you wish to convert to binary: \n"))

num_bin = []

for i in reversed(range(0, 8)):
    i = 2**i
    if num_dec >= i:
        num_dec = num_dec - i
        num_bin.append("1")
    elif num_dec < i:
        num_bin.append("0")

print("".join(num_bin))
