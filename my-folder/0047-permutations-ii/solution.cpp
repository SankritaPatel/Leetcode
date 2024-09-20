class Solution {
public:
    void helper(vector<int> a, vector<vector<int>> &ans, int idx){
        if(idx==a.size()){
            ans.push_back(a);
            return ;
        }
        for(int i=idx;i<a.size();i++){
            if(i!=idx and a[i]==a[idx]){
                continue;
            }
            swap(a[i], a[idx]);
            helper(a, ans, idx+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        helper(nums, ans, 0);
        return ans;
    }
};
