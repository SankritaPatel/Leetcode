class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::string sorted_s1 = sortString(s1);
        int s1_length = sorted_s1.length();
        int s2_length = s2.length();

        for (int i = 0; i <= s2_length - s1_length; i++) {
            std::string substring = s2.substr(i, s1_length);
            if (sorted_s1 == sortString(substring)) {
                return true;
            }
        }
        return false;
    }

private:
    std::string sortString(std::string s) {
        std::sort(s.begin(), s.end());
        return s;
    }
};
