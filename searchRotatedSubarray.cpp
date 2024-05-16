class Solution {
public:
   int search(vector<int>& nums, int target) {
     return searchInRotatedarray(nums, target, 0, nums.size() - 1);
}

int searchInRotatedarray(vector<int> &nums, int target, int left, int right){
 if(left > right){
     return -1;
 }
 int mid = (left + right) /2;
 if(nums[mid] == target){
     return mid;
 }
 if(nums[left] <= nums[mid]){
     if(target >= nums[left] && target <nums[mid]){
         return searchInRotatedarray(nums, target, left, mid-1);
     }
     return searchInRotatedarray(nums, target, mid+1, right );
 }
 if(target > nums[mid] && target <= nums[right]){
     return searchInRotatedarray(nums, target , mid+1, right);
 }
 return searchInRotatedarray(nums, target , left, mid-1);
}
};