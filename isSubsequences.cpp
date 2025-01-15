class Solution {
public:

//Algorithm : Two pointer approach
//TC: O(n)
//SC:O(1)
    bool isSubsequence(string s, string t) {
        int j =0;
       for(int i=0; i<t.size(); i++){
            if(j<s.size() && s[j] == t[i]){
                j++;
            }
       }
       if(j == s.size()){
        return true;
       }
       return false;
    }
};