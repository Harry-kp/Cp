def solve(i,j,matrix):
        if j<0 or j == len(matrix):
            return float('inf')
        if i == len(matrix)-1:
            return matrix[i][j]
        return matrix[i][j] + min(
            solve(i+1,j-1,matrix),
            solve(i+1,j,matrix),
            solve(i+1,j+1,matrix))
class Solution:

    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        return min([solve(0,j,matrix) for j in range(len(matrix))])