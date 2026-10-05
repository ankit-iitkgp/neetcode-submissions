class Solution:
    def maxArea(self, heights: List[int]) -> int:
        n = len(heights)
        left, right = 0, n-1
        maxArea = 0
        while left < right:
            area = (right-left)*min(heights[left], heights[right])
            maxArea = max(area, maxArea)
            if heights[left] < heights[right]:
                left += 1
            else:
                right -= 1
        return maxArea