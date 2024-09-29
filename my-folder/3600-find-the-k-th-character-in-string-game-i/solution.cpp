class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        while (ans.size() < k) {
            string newString = "";
            for (char i : ans) {
                newString += (i + 1); 
            }
            ans += newString; 
        }
        return ans[k - 1]; 
    }
};

