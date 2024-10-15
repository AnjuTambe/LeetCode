class Solution {
public:
   
   int search(vector<int> &nums, int target){
    int st = 0 , end = nums.size()-1;
    while(st <= end){
        int mid = st + (end-st)/2;  // find the mid

        if(nums[mid] == target){
            return mid;
        }
        // after that check if left half is sorted or right half is sorted
        //  left half sorted
        if(nums[st] <= nums[mid]){
             //check target is lies between the st and mid
            if(nums[st] <= target && target <= nums[mid]){
                end = mid-1;
            }else{
                st = mid+1;
            }

        }
        else{
            //right half sorted
             // target is lies between the mid and end
            if(nums[mid] <= target && target <= nums[end]){
            st = mid+1;
            }else{
            end = mid-1;
            }
        }
    }
    return -1;
}
};