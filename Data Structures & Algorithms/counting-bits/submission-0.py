class Solution:
    def countBits(self, n: int) -> List[int]:
        i = 0
        offset = 2**0
        dp = [0]*(n+1)
        for j in range(1, n+1):
            rem = j-offset
            dp[j] = 1 + dp[rem]
            if rem == offset-1:
                i+=1
                offset = 2 ** i
        return dp
