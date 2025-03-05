class Solution {
public:
    
    //Solution : 2 using Memoization (Top-down)   
    //TimeComple : O(n)
    //SpaceCompl : O(n) 
        
    int climbStairsHelper(int n , vector<int>&dp)  {


            // base case
            if(n <=2) {
                return n;
            }
           
           // check first if we had calculate this value before
           if(dp[n] != -1){
            return dp[n];
           }
          return  dp[n] = climbStairsHelper(n-1 , dp) + climbStairsHelper(n-2 , dp);
 
        }

      int climbStairs(int n){
        vector<int>dp(n+1 , -1);
        return climbStairsHelper(n ,dp);
      }
       
      
       
};
