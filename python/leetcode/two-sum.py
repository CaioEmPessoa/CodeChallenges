'''
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

## This code could be REALLY polished.
## And I just read that the code ALWAYS have a correct solution, when I tought it wanted the closest possible sum...
'''

class Solution(object):
    def twoSum(self, nums, target):
        steps = target*2
        answr = []
        temp_steps = 0
        temp_list = list(nums)

        for num1 in nums:
            temp_list[temp_list.index(num1)] = "x"
            for num2 in temp_list[:temp_list.index("x")] + temp_list[temp_list.index("x")+1:]:
                add = num1 + num2
                if add > target:
                    while add != target:
                        add-=1
                        temp_steps+=1
                    if temp_steps < steps:
                        steps = temp_steps
                        
                        answr = [nums.index(num1), temp_list.index(num2)]
                elif add < target:
                    while add != target:
                        add+=1
                        temp_steps+=1
                    if temp_steps < steps:
                        steps = temp_steps
                        answr = [nums.index(num1), temp_list.index(num2)]
                
                else:
                    answr = [nums.index(num1), temp_list.index(num2)]
                    steps = 0
                    break
            temp_list = list(nums)
        answr.sort()
        return answr