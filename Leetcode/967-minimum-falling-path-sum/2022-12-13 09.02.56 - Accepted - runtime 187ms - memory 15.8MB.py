

class Solution:
    
    
    def solve(self,i,j,matrix):
        if j<0 or j == len(matrix):
            return float('inf')
        if i == len(matrix)-1:
            return matrix[i][j]
        if (i,j) in self.cache:
            return self.cache[(i,j)]
        x = matrix[i][j] + min(
            self.solve(i+1,j-1,matrix),
            self.solve(i+1,j,matrix),
            self.solve(i+1,j+1,matrix))
        self.cache[(i,j)] = x
        return x

    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        self.cache = {}
        return min([self.solve(0,j,matrix) for j in range(len(matrix))])