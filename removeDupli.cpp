// brute force solution :
// TC: O(n^2)   SC: O(n)
class Solution{
public:
 int removeDuplicates(vector<int> &nums){
    //base case
    if(nums.size()<=2){
        return nums.size();
    }
    vector<int> result;
    for(int i=0; i<nums.size(); i++){
        int count = 1;
        while( i+1 < nums.size() && nums[i] == nums[i+1]){
          i++;
          count++;
        }

        count = min(count, 2);
        for(int j=0; j<count; j++){
           result.push_back(nums[i]);
        }
    }
    //copy the result array back to the original array
    for(int i=0; i<result.size() ;i++){
        nums[i] = result[i];
    }
    return result.size();
 }
};