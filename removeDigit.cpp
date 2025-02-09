class Solution {
public:
    string removeDigit(string number, char digit) {
      
      string maxString = "";

      for(int i=0; i<number.size() ; i++){
        if(digit == number[i]){
            string temp = number.substr(0, i) + number.substr(i + 1);

            maxString = max(temp , maxString);
        }
      }
      return maxString;
    }
};

