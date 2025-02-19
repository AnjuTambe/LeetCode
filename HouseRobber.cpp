class Solution {
public:
//Algorithm  : Tabulation  (bottom-up approach)
//TC : O(n)
//SC : O(n)    // used dp array 
    int rob(vector<int>& nums) {
     if(nums.empty()) return 0;
     if(nums.size() == 1) return nums[0];
      int n = nums.size();
    vector<int> dp(n);         // create a dp array with n size

    // base case : 
    dp[0] = nums[0];
    dp[1] = max(nums[0] , nums[1]);

    for(int i=2 ; i<n ; i++){
        dp[i] = max(dp[i-1] , dp[i-2] + nums[i]);
    }
    
    return dp[n-1];
    }
};