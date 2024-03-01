class Solution {
public:
    int lengthOfLastWord(string s){
        int size= s.length();
        int count =0;
        for(int i = size-1; i>=0; i--){
            if(s[i] != ' '){
                count++;
            }
             else {
                if( count > 0){
                    return count;
                }
            }
        }
        return count;
    }
};