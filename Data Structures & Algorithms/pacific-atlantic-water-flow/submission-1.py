class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        pacific = set()
        atlantic = set()

        m, n = len(heights), len(heights[0])

        def dfs(isPacific: bool, i: int, j:int):
            my_set = pacific if isPacific else atlantic
            my_set.add((i,j))
            dirs = [(0,1),(0,-1),(1,0),(-1,0)]
            for dir in dirs:
                x, y = i+dir[0], j+dir[1]
                if x>=0 and x<m and y>=0 and y<n and (x,y) not in my_set and heights[x][y]>=heights[i][j]:
                    dfs(isPacific, x, y)            

        for i in range(m):
            if (i,0) not in pacific:
                dfs(True, i, 0)
            if (i, n-1) not in atlantic:
                dfs(False, i, n-1)

        for j in range(n):
            if (0,j) not in pacific:
                dfs(True, 0, j)
            if (m-1, j) not in atlantic:
                dfs(False, m-1, j)

        answer = []
        for point in atlantic:
            if point in pacific:
                answer.append([point[0],point[1]])
        return answer
        
