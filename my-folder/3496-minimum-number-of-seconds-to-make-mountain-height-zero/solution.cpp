#include <vector>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;

        auto canAchieve = [&](long long timeLimit) {
            long long totalWork = 0;
            for (auto& workerTime : workerTimes) {
                long long lowHeight = 0, highHeight = mountainHeight;
                while (lowHeight < highHeight) {
                    long long midHeight = (lowHeight + highHeight + 1) / 2;
                    if (workerTime * midHeight * (midHeight + 1) / 2 <= timeLimit)
                        lowHeight = midHeight;
                    else
                        highHeight = midHeight - 1;
                }
                totalWork += lowHeight;
                if (totalWork >= mountainHeight) return true;
            }
            return totalWork >= mountainHeight;
        };

        while (left < right) {
            long long mid = (left + right) / 2;
            if (canAchieve(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

