class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> count_map;
        vector<int>ans;
        for(int num: nums){
            count_map[num]++;
            if (count_map[num]==2){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
