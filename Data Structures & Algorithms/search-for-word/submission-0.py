class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        w = len(word)
        def dfs(i, j, k)-> bool:
            if k == w-1:
                return True
            k += 1
            c = board[i][j]
            dirs = [(0,1),(0,-1),(-1,0),(1,0)]
            board[i][j] = '#'
            for dir in dirs:
                x, y = i+dir[0], j+dir[1]
                if x>=0 and x<m and y>=0 and y<n and board[x][y] == word[k]:
                    if dfs(x,y,k):
                        return True
            board[i][j] = c
            return False
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == word[0]:
                    if dfs(i,j,0):
                        return True
        return False