l = [1, 2, 3, 4]
index_to_remove = 2  # Dynamic index
l = l[:index_to_remove] + l[index_to_remove + 1:]  # Removes the item at the specified index
print(l)