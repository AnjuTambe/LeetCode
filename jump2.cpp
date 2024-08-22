#include<vector>
#include<algorithm>
class Solution {
public:
    int jump(vector<int>& nums) {
        int destination = nums.size()-1;
        int totalJumps =0;
        int coverage =0;
        int lastIdxJump = 0;
        //base condition
       if(nums.size() == 1){
        return 0;
       }
        for(int i=0; i<nums.size(); i++){
             coverage = std::max(coverage, i+nums[i]);

            if(i == lastIdxJump){
                lastIdxJump = coverage;
                totalJumps++;

            if(coverage >= destination){
                return totalJumps;
            }
        }
    }
        return totalJumps;
    }
};