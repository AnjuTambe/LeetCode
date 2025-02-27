class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> result;
        unordered_map<int, int> map;
        int count =0;
        for(int el : nums){
                map[el]++;  // Automatically assign and increment the count in the map
     }

        // building the min-heap(priority_queue) to store the element of k-size

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int, int>>>minHeap;

        for(auto el :map){

            int value = el.first;
            int freq = el.second;

            minHeap.push({freq , value});

            //if size greater then k 
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
           

            while(!minHeap.empty()){
                result.push_back(minHeap.top().second);
                minHeap.pop();
            }

             return result;
        }
       
    
        };
