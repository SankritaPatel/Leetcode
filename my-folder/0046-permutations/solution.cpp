class Solution {
public:
    void permute(vector<int> &a, int idx, vector<vector<int>> &ans) {
    if (idx == a.size()) {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i++) {
        swap(a[i], a[idx]); // Swap current element with the first element
        permute(a, idx + 1, ans); // Recur for the next index
        swap(a[i], a[idx]); // Backtrack (restore original order)
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; // Declare a vector to store permutations
        permute(nums, 0, ans);
        return ans;
    }
};
