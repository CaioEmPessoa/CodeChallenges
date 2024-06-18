from math import floor
lootbox_options = {
    "itemOne":{
        "name":"ItemOne",
        "chance":200
    },
    "itemTwo":{
        "name":"itemTwo",
        "chance":30
    },
    "itemThree":{
        "name":"itemThree",
        "chance":19
    },
    "itemFour":{
        "name":"itemFour",
        "chance":1
    },
}


last_index = 0
now_index = 0
total_sum = 0
lootbox_size = 100

# create a list of 100 itens, can be anything but the bigger the more precise the percenteges can be.
# if you want a item with 0.0001 chance would need to create a list of 10000 itens, but this take some time
lootbox_itens = ["null" for i in range(lootbox_size)]

for option in lootbox_options:

    # get option info on dict, since its only a keyword here
    option = lootbox_options[option]

    # just checks if all percenteges are correct, if ther surpass the size of lootbox, ends program with error
    total_sum += option["chance"]/lootbox_size
    if total_sum > 1:
        raise Exception("Chances surpass size of lootbox")

    # multiply the size of the lootbox size (in this case 100, could be anything but its more precise)
    # by the chance divided by 100, so it gets until what index it should place the item
    # and after that it sums with the last index, so it appears right before it.
    now_index = floor(len(lootbox_itens)*option["chance"]/100)+last_index
    
    for item in range(last_index, now_index):
        lootbox_itens[item] = option["name"]

    last_index = now_index

print(lootbox_itens)