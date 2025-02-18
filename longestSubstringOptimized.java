


class Solution{        // TC : O(n) and SC: O(min(n, 256))

    public int lengthOfLongestSubstring(String s){

        HashSet<Character> set = new HashSet<>(); 
        int left = 0;
        int maxLength = 0;

        for(int right =0; right<s.length(); right++){
            //if the right element already present in the set
            while(set.contains(s.charAt(right))){
                set.remove(s.charAt(left));
                left++;
            }

            int w = right - left + 1 ;
            //if the right element not present then add it to the set

            set.add(s.charAt(right));
            maxLength = Math.max(maxLength , w);
        }
        return maxLength;
    }
};