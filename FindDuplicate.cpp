class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       
    //    unordered_set<int> s;    // TC : O(n)  SC : O(n)

    //     for(int val : nums){
    //     if(s.find(val) != s.end()){
    //         return val;
    //     }
    //     s.insert(val);
    //  }
    //  return -1;


// we need to slove in SC : O(1) 
// Floyd's Cycle Detection Algorithm (slow and fast pointer approach) used for TC : O(n) , SC : O(1)
    int slow = nums[0] , fast = nums[0];
    // first do the work
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
                                           

    }while(slow != fast);

    slow = nums[0];

    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
   return slow;
}
    
};