import java.util.HashSet;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int maxLength = 0;
        for(int i=0; i< s.length(); i++){
           
           String str = "";
           HashSet<Character> set = new HashSet<>();
            for(int j = i ; j<s.length() ;j++){
               if(set.contains(s.charAt(j))){
                break;
               }

               str = str + s.charAt(j);
                set.add(s.charAt(j));
                maxLength = Math.max(maxLength , set.size());
            }
        }
        return maxLength;
       
    }
} {
    
}
