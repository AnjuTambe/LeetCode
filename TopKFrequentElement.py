import heapq
from collections import Counter
class Solution(object):
    def topKFrequent(self, nums, k):
        # Input: nums = [1,1,1,2,2,3], k = 2

        # Output: [1,2]
        # count the freuency  :
    
        freq = Counter(nums)
        # {1: 3 , 2 : 2 , 3 : 1}
        
        heap = []
        for num , count in freq.items() : 
            heapq.heappush(heap, (count , num))
            if len(heap) > k :
                heapq.heappop(heap)

        return [num for _, num in heap]   
