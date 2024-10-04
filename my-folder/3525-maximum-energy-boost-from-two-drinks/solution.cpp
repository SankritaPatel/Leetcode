class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        long long prev2_A = 0, prev1_A = 0, prev2_B = 0, prev1_B = 0;
        for (int i = 0; i < n; i++) {
            long long curr_A = max(prev1_A, max(prev2_A, prev2_B)) + energyDrinkA[i];
            long long curr_B = max(prev1_B, max(prev2_B, prev2_A)) + energyDrinkB[i];
            prev2_A = prev1_A;
            prev1_A = curr_A;
            prev2_B = prev1_B;
            prev1_B = curr_B;
        }
        return max(prev1_A, prev1_B);
    }
};
