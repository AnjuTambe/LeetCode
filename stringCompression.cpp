class Solution {
public:
    int compress(vector<char>& chars) {   // O(n)
        int idx = 0;
        for(int i=0; i< chars.size(); i++){
            char ch = chars[i];
            int count = 0;

            while(i < chars.size() && chars[i] == ch){   //using same iterator i so no change in TC
                count++;
                i++;
            }

            if(count == 1){
                chars[idx++] = ch;
            }
            else{
                chars[idx++] = ch;
                string str = to_string(count);  // 12 => "12"
                for(char dig : str){         //'1''2'
                    chars[idx++] = dig;
                }
            }
            i--;
        }
        chars.resize(idx);
        return idx;
    }
};