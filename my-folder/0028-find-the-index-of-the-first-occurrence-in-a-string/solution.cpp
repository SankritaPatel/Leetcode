class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; // Edge case: empty needle

        int haystackLen = haystack.size();
        int needleLen = needle.size();
        
        // Iterate only until there's enough room for the needle
        for (int i = 0; i <= haystackLen - needleLen; i++) {
            int j = 0;
            // Compare substring of haystack with needle
            while (j < needleLen && haystack[i + j] == needle[j]) {
                j++;
            }
            // If we have matched the entire needle, return the starting index
            if (j == needleLen) {
                return i;
            }
        }
        return -1; // If needle is not found
    }
};

