#include <string>
#include <algorithm> // for std::count

class Solution {
public:
    int countKConstraintSubstrings(std::string s, int k) {
        int ans = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) { // j goes from i + 1 to n
                std::string sub = s.substr(i, j - i); // get the substring from i to j
                if (std::count(sub.begin(), sub.end(), '1') <= k || 
                    std::count(sub.begin(), sub.end(), '0') <= k) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

