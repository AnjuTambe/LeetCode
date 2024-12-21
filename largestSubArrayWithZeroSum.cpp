#include <iostream>
#include <vector>
#include "unordered_map"
#include "unordered_set"
using namespace std;


 int largestSubArrayWith0Sum(vector<int> arr){
     unordered_map<int , int> m;   //it will store the pair of sum , idx
     int sum = 0;
     int ans = 0;
     for(int j=0; j<arr.size(); j++){
         sum += arr[j];

         if(m.count(sum)){   // if present in the map then calculate the length
             int currLen = j- m[sum]; // j- idx
             ans = max(ans , currLen);

         }else{
             m[sum] = j;  // if not present in the map just add it
         }
     }
     return ans;
 }



int main() {
   vector<int> arr = {15,-2, 2,-8,1,7,10};
   cout << "Length Of Max SubArray With 0 Sum is : " << largestSubArrayWith0Sum(arr) << endl;
    return 0;
}
