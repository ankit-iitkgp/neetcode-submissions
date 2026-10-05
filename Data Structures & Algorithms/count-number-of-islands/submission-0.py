class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m, n = len(grid), len(grid[0])
        vis = [[False] * n for i in range(m)]
        count = 0

        def dfs(i, j):
            vis[i][j] = True
            dirs = [(0,1),(0,-1),(1,0),(-1,0)]
            for dir in dirs:
                x, y = i+dir[0], j+dir[1]
                if x>=0 and x<m and y>=0 and y<n and grid[x][y] == "1" and not vis[x][y]:
                    dfs(x,y)

        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and not vis[i][j]:
                    dfs(i,j)
                    count += 1
        return count