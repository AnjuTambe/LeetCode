class Solution(object):
    def canAttendMeetings(self, intervals) :
        # sort the intervals by the start time 
        intervals.sort(key = lambda x : x[0])
        
        for i in range(1, len(intervals)) : 
           i1 = intervals[i-1]
           i2  = intervals[i]

           if i1[1] > i2[0] : 
              return False

        return True   

