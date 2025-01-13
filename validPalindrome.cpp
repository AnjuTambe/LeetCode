class Solution {
public:
//Algorithm used : two pointer aproach
//TC : O(n)
//SC: O(1)
    bool isPalindrome(string s) {
        
        // first we assign the st and end index
        int st = 0;
        int end = s.size()-1;

        while(st < end){

            //Check if the values are not Alfanumeric for st
            while(st < end && !isalnum(s[st])){
                st++;
            }
            //Check if the values are not Alfanumeric for end

            while(st < end  && !isalnum(s[end])){
                end--;
            }
            // if they are not alfanumeric values then check this 
            // make this tolower first
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }

            st++;
            end--;
        }
        return true;   // it's a palindrome
    }
};