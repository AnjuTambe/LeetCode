class Solution {
public:
 string addBinary(string a, string b){
     string result;
     int i= a.length()-1;
     int j= b.length()-1;
     int sum; 
     int carry =0;
     while( i>=0 ||  j >=0 || carry){
         sum =carry;
         if(i >=0){
             sum = sum + a[i] - '0';
             i--;
         }
         if(j >=0){
             sum = sum + b[j] - '0';
             j--;
         }
         result = char('0' + sum %2) + result;
         carry = sum /2;
     }
     return result;
 }
   
};