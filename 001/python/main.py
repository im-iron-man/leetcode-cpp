class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        cache = {}
        for i, num in enumerate(nums):
            r = target - num
            if r in cache:
                return cache[r], i
            cache[num] = i
        return None
