class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        l1, l2, l3 = len(s1)+1, len(s2)+1, len(s3)+1
        dp = [[False] * l2 for i in range(l1)]
        dp[0][0] = True
        if l3 != l1+l2-1:
            return False
        for i in range(l1):
            for j in range(l2):
                if i > 0 and s3[i+j-1] == s1[i-1] and dp[i-1][j]:
                    dp[i][j] = True
                elif j > 0 and s3[i+j-1] == s2[j-1] and dp[i][j-1]:
                    dp[i][j] = True

        return dp[l1-1][l2-1]