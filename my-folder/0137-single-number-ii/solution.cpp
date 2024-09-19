class Solution {
public:
    bool getBit(int n, int pos) {
        return (n & (1 << pos)) != 0;
    }

    int setBit(int n, int pos) {
        return n | (1 << pos);
    }

    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0; 
            for (int j = 0; j < nums.size(); j++) {
                if (getBit(nums[j], i)) {
                    sum++;
                }
            }
            // If sum is not a multiple of 3, set that bit in the result
            if (sum % 3 != 0) {
                result = setBit(result, i);
            }
        }

        return result;
    }
};
