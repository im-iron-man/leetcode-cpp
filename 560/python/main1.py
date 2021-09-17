# O(n^2)
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = 0
        for i in range(len(nums)):
            s = 0
            for j in range(i, len(nums)):
                s += nums[j]
                if s == k:
                    cnt += 1
        return cnt
