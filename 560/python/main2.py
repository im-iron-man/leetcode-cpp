# O(n^2)
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        s, pre_sum = 0, [0]
        for num in nums:
            s += num
            pre_sum.append(s)

        cnt = 0
        for i in range(len(pre_sum)):
            for j in range(i + 1, len(pre_sum)):
                if pre_sum[j] - pre_sum[i] == k:
                    cnt += 1

        return cnt
