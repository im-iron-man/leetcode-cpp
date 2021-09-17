# O(n)
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        s, pre_sum = 0, [0]
        for num in nums:
            s += num
            pre_sum.append(s)

        cnt, d = 0, {}
        for s in pre_sum:
            if s - k in d:
                cnt += d[s - k]

            if s in d:
                d[s] = d[s] + 1
            else:
                d[s] = 1

        return cnt
