class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        dp1 = [0] * n
        dp2 = [0] * n
        dp1[0] = 0
        dp1[1] = nums[0]
        for i in range(1, n-1):
            dp1[i+1] = max(dp1[i], dp1[i-1]+nums[i])
        dp2[1] = nums[1]
        for i in range(2, n):
            dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i])
        return max(dp1[n-1], dp2[n-1])