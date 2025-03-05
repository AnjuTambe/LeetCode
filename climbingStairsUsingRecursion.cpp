class Solution {
public:
    int climbStairs(int n) {
        //Solved using recursion.
        //TC: O(2^n) not passing all the test cases because its calling the same fucn again and again
        //SC : O(n) because of recursion, used the call stack
         // base case
            if(n==1){
                return 1;
            }
            if(n==2){
                return 2;
            }

            return climbStairs(n-2) + climbStairs(n-1);
            
        }
       
};
