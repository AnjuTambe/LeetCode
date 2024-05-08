class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
   std::unordered_set <int> numSet;
   for(int i=0; i<nums.size(); i++){
     int num = nums[i];
     if(numSet.contains(num)){
        return true;
     }
     numSet.insert(num);
   }
   return false;
}
};