class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        std::unordered_set<std::string> bannedSet(bannedWords.begin(), bannedWords.end());
        int ans = 0;

        for (const auto& word : message) {
            if (bannedSet.find(word) != bannedSet.end()) {
                ans++;
                if (ans >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};
