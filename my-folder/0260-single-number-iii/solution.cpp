class Solution {
public:
    bool setBit(int n, int pos){
        return (n & (1<<pos)) !=0;
    }

    vector<int> singleNumber(vector<int>& nums) {
        int xorSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            xorSum ^=nums[i];
        }
        int pos = 0;
        while((xorSum &(1<<pos))==0){
            pos++;
        }
        int newXor = 0;
        for(int i=0;i<n;i++){
            if(setBit(nums[i], pos)){
                newXor^=nums[i];
            }
        }
        int secondUnique = xorSum ^ newXor;
        return {newXor, secondUnique};
    }
};
