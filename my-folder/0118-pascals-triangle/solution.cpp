class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        for (int i = 0; i < numRows; ++i) {
            vector<int> curr(i + 1, 1); // Initialize a row with 1s
            
            for (int j = 1; j < i; ++j) {
                curr[j] = curr[j - 1] * (i - j + 1) / j;
            }
            
            ans.push_back(curr);
        }
        
        return ans;
    }
};

