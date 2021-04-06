class Solution(object):
    def twoSum(self, nums, target):
        cache = {}
        for i, num in enumerate(nums):
            r = target - num
            if r in cache:
                return cache[r], i
            cache[num] = i
        return None
