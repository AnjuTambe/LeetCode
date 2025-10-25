class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):  # Fixed spelling
        n = len(s)
        max_length = 0
        for i in range(n):
            for j in range(i, n):
                substring = s[i:j+1]
                distinct_chars = set(substring)  # Fixed typo
                if len(distinct_chars) <= 2:     # Fixed condition
                    max_length = max(max_length, j - i + 1)
                else:
                    break  # Only break when invalid
        return max_length  # Fixed variable name