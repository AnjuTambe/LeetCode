class Solution {
public:
// Time complexity : O(n)
    int maxProduct(vector<int>& nums) {
     if(nums.empty()) return 0;
    int totalMax = nums[0];
    int minProduct = nums[0];
    int maxProduct = nums[0];

    for(int i=1; i<nums.size(); i++){
        int curr = nums[i];
        int prevMinP = minProduct;
        int prevMaxP = maxProduct;

        minProduct = min(curr , min (curr * prevMinP , curr * prevMaxP));
        maxProduct = max(curr , max(curr * prevMaxP , curr * prevMinP));

         totalMax = max(maxProduct , totalMax);
    }
    return totalMax;
 }
};
    
// brute force approach : O(n^2)
    // int maxProduct = INT_MIN;
    // for(int i=0; i<nums.size(); i++){
    //     int product = 1;
    //     for(int j =i; j<nums.size(); j++){
    //         product = product * nums[j];       // 1*2 = 2
    //         maxProduct = max(product , maxProduct);    //(2, INT_MIN) = 2
    //     }
    // }
    // return maxProduct;

    

