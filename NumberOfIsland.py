
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:



        #  Rules :  1: Find the num of islands
        #           2: island is formed by connecting adjacent horizontally land and vertically
        # we will go to each cell on the grid and apply the dfs on this. 
        # what the dfs will do, go to the all four direction of the cell and look if you found the water
        # then break the dfs or if not then go to another cell and apply the dfs on that.
        # once you found the one island then incerase its count. 
        
        # if grid is empty
        if not grid : 
            return

        rows , cols  = len(grid), len(grid[0])

        def dfs(r : int , c : int) -> None:
             # Base case
            if r < 0 or r >= rows or c  < 0  or c >= cols or grid[r][c] != '1' : 
              return
            grid[r][c] = '0' # mark as a visited

            dfs(r +1 ,c)
            dfs(r-1 , c)
            dfs(r, c+1)
            dfs(r, c-1)
         
        numOfIsland =0
    
        for r in range(rows) : 
            for c in range(cols) :
                if grid[r][c] == '1' : 
                    numOfIsland += 1
                dfs(r,c)


        return numOfIsland        
