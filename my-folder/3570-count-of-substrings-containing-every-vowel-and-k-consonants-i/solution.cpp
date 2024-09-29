#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    int countOfSubstrings(std::string s, int k) {
        std::unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int count = 0;
        int n = s.length();

        for (int start = 0; start < n; ++start) {
            std::unordered_map<char, int> vowel_count;
            int consonant_count = 0;
            
            for (int end = start; end < n; ++end) {
                char char_end = s[end];

                if (vowels.count(char_end)) {
                    vowel_count[char_end]++;
                } else if (isalpha(char_end)) {
                    consonant_count++;
                }
                
                // Check if all vowels are present
                if (vowel_count.size() == vowels.size()) {
                    if (consonant_count == k) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};

