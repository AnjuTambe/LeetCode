class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
       
       # assign the complete grid to zero
        grid = [[0] * n for _ in range(m)]

        for i in range(m) : 
            for j in range(n) :

                # base case 

                if i== 0 or j==0 : 
                    grid[i][j] = 1

                else:
                    # apply the formula
                    grid[i][j] = grid[i-1][j] + grid[i][j-1]

        return grid[m-1][n-1]            


        