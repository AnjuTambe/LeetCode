class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=0;
        for(int i=0; i< nums.size(); i++){
            int j = i+1;
            if(i == nums.size()-1){
                nums[k] = nums[i];
                break;
            }
            if(nums[i] != nums[j]){
               nums[k] = nums[i];
                k++;                
            }
        }
        return k+1;
    }
};