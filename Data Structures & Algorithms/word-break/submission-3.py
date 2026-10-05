from functools import lru_cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        @lru_cache(None)
        def dfs(s):
            if not s:
                return True
            m = len(s)
            for i in range(1,m+1):
                if s[0:i] in words:
                    if dfs(s[i:]):
                        return True
            return False
        return dfs(s)