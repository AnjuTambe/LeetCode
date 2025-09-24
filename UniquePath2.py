class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:

        # Now we use the cache to remember this function call

        @cache
        def dp(r,c) : 
            
           N, M = len(obstacleGrid) , len(obstacleGrid[0])  # row , col 
              # base cases
           if r == N or c == M or obstacleGrid[r][c] == 1: 
                 return 0
           if (r,c) == (N-1 , M-1) : return 1 # we reached the destination here
           return dp(r+1, c) + dp(r, c+1)

        return dp(0,0) 
         
