class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {   
        // This is solution in O(n) using Bucket Sort    
        unordered_map<int, int>map;

        for(int el : nums){
               map[el]++;
        }

        // create a bucket array where index = frequency

        int n = nums.size();
         
         vector<vector<int>> bucket(n+1);
         // index = freq
         // val = element

         for( auto it : map){

            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);  // go to that freq(index) and push the element which has same freq
        }

        // pick element from right to left in the bucket
          
          vector<int> result;
          for(int i = n ; i >=0 ; i--){
             
             if(bucket[i].size() == 0)
                continue;

               while(bucket[i].size() > 0 && k>0){
                  result.push_back(bucket[i].back());    // in the constant time
                  bucket[i].pop_back();
                  k--;
               } 

          }
          return result;
}
};