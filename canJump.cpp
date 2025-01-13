class Solution {
public:

// Algorithm used : Greedy Algorithm
//Time Complexity : O(n)
//Space Complexity : O(1)
    bool canJump(vector<int>& nums) {
       //Iniatally the final position as the last index
       int finalPos = nums.size()-1;

       //start with the last index
       for(int idx = nums.size()-2; idx>=0; idx--){
        if(idx + nums[idx] >= finalPos){  // if you can reach the finalPos from this index
            finalPos = idx;   // update the finalPos flag
        }
       }
       return finalPos == 0; // if we can reach the starting index then we can make the jump possibe

    }
};