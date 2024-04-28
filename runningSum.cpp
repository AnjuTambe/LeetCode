class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result; 
        int i=0;
        result.push_back(nums[i]);
        int sum = nums[i];
        for(int j = i+1; j < nums.size(); j++){
            sum = sum + nums[j];
            result.push_back(sum);
        }
        return result;
    }
};