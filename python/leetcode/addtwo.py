class Solution(object):
    def normalList(self, l1, l2):
        print(type(l1))
        l1 = map(str, reversed(l1))
        l2 = map(str, reversed(l2))
        return list(map(int, reversed(str(int("".join(l1))+int("".join(l2))))))
