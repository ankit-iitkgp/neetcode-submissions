from functools import lru_cache

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)
        @lru_cache(None)
        def dfs(s):
            if not s:
                return True
            for word in words:
                n = len(word)
                if s.startswith(word):
                    if dfs(s[n:]):
                        return True
            return False
        return dfs(s)