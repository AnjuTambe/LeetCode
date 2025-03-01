class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
            // TC : O(n logn)
            //   sort(nums.begin() , nums.end() , std::greater<int>());
            //   return nums[k-1];

            // TC : O(n*logK)
            //Sc : O(K)
            //using min-heap (priority_queue)
            priority_queue<int , vector<int>, greater<int>> pq;


            for(int el : nums){
                pq.push(el);      // pushing the element in the queue
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};    