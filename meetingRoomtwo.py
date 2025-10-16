import heapq
class Solution(object):
    def minMeetingRooms(self , intervals) : 

        # base case : 
        if not intervals : 
            return 0

        # sort by the start time
        intervals.sort(key = lambda x : x[0])

        # take a empty min heap
        heap = []

        for start , end in intervals : 
            if heap and heap[0] <= start : 
                heapq.heappop(heap)     # free the room
            
            heapq.heappush(heap , end)  # assign the room for current meeting room

        return len(heap)                 
