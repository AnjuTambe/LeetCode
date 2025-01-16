class Solution {
public:
//Algorithm : Used the set DS to store the unique element
//TC : O(n) iterate through the whole array
// SC: O(n) used set to store
    int minimumOperations(vector<int>& nums) {
        
        set<int>s; // creats the set data structure to store the unique element

        for(int i=0; i< nums.size(); i++){
            if(nums[i] > 0){
                s.insert(nums[i]);   // insert the unique and > 0 element every time
            }
        }
        return s.size();   // finally return the set size which is eqaul to minimum operations to make array zero
    }
};