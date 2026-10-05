class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda i: i[1])
        curr_end = 0
        ans = 0
        for i, interval in enumerate(intervals):
            if i>0 and interval[0] < curr_end:
                ans += 1
                continue
            else:
                curr_end = interval[1]
        return ans