class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        int count[26] = {0};
        for(int i=0; i<s.length(); i++){
            int index = s[i] - 'a';  //index
            count[index]++;
        }
        for(int i=0; i<t.length(); i++){
            int index = t[i] - 'a';
            if(count[index] == 0){
                return false;
            }
            count[index]--;
        }
        return true;
    }
};