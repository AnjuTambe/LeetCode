class Solution {
public:
    bool canJump(vector<int>& nums) {
       int finalPos = nums.size()-1;
       for(int idx = nums.size()-2; idx>=0; idx--){
           if(idx + nums[idx] >= finalPos){
              finalPos = idx;
           }
       }
       return finalPos == 0; 
    }
};