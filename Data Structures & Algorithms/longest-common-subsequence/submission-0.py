class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m,n = len(text1), len(text2)
        lcs = [[0] * (n+1) for _ in range(m+1)]
        

        for i in range(1,m+1):
            for j in range(1,n+1):
                lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j])
                if text1[i-1] == text2[j-1]:
                    lcs[i][j] = max(lcs[i-1][j-1]+1, lcs[i][j])
        return lcs[m][n]


        