from functools import lru_cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        m = len(s)
        @lru_cache(None)
        def dfs(i):
            if i==m:
                return True
            for j in range(i+1, m+1):
                if s[i:j] in words:
                    if dfs(j):
                        return True
            return False
        return dfs(0)