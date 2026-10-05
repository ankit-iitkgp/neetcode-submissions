class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        left, right = 0, n-1
        while(left<right):
            for i in range(n):
                matrix[left][i], matrix[right][i] = matrix[right][i], matrix[left][i]
            left += 1
            right -= 1
        
        for i in range(n):
            for j in range(i+1, n):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        