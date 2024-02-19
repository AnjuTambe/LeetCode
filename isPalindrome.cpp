class Solution {
public:

    bool isPalindrome(int x) {
     int sum=0;
     int rem;
     int temp =x;    
     while(x > 0){                          
        rem = x % 10;                
        sum = (sum * 10LL) + rem;            
        x = x / 10;                         
    }
      return temp == sum;
     
    }
  
};