class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int j =1;
      if(nums.empty()){
        return 0;
      }
      for(int i=1; i<nums.size(); i++){
        if(nums[i] != nums[i-1]){
            nums[j] = nums[i];
            j++;
        }
      }
    return j;
    }
};

//Algorithm : two pointer technique , fast pointer i , and slow pointer j.
//TC : O(n)
//SC: O(1)