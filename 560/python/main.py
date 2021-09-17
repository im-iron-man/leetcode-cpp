# O(n^3)
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        cnt = 0
        for i in range(len(nums)):
            for j in range(i + 1, len(nums) + 1):
                s = sum(nums[i:j])
                if s == k:
                    cnt += 1
        return cnt
