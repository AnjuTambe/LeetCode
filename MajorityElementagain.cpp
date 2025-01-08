class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
    // using hash table TC :  worst case when the reshashing used O(n^n)
    //  Avg case : O(n)+ O(n) => 2 O(n) => O(n) always
    // SC : O(n)

     unordered_map<int , int>map;
     for(int i=0; i<nums.size() ;i++){ // O(n)
       if(map.count(nums[i])){     // to store the nums and their count in the map
           map[nums[i]]++;
       }
       else{
       map[nums[i]] = 1;    //if not exits then create the new num in the map and assign the num 1 to it
     }
    }

     for(auto& p : map){                 //O(n)
        if(p.second > nums.size()/2){
            return p.first;
        }
     }

      return -1;
    }
};  