class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        num_set = set(nums)
        longest = 1
        for num in nums:
            if num-1 not in num_set:
                count =1
                i = num + 1
                while i in num_set:
                    count +=1
                    i += 1
                longest = max(longest, count)
        return longest