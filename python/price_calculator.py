shopping_price = float(input())
shopping_ammount = int(input())

normal_price = shopping_price*shopping_ammount

discount = 0.1 + shopping_ammount * 0.01
discount_price = normal_price * discount

final_price = normal_price - discount_price

print(f"{normal_price:.2f}")
print(f"{final_price:.2f}")