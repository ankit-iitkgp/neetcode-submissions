class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ans = []
        for i, num in enumerate(nums):
            if target == num:
                ans.append([num])
            new_target = target - num
            if new_target < min(nums):
                continue
            combinations = self.combinationSum(nums[i:], new_target)
            for comb in combinations:
                ans.append([num] + comb)
        return ans