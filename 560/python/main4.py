# O(n)
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        s, d = 0, {0: 1}
        cnt = 0
        for num in nums:
            s += num

            if s - k in d:
                cnt += d[s - k]

            if s in d:
                d[s] = d[s] + 1
            else:
                d[s] = 1

        return cnt
