#include <vector>

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        constexpr int kInfCost = 1e9;
        vector<vector<int>> dp (k+2, vector<int>(n, kInfCost));
        dp[0][src] = 0;

        for (int i = 1; i < k+2; i++) {
            //inherit mininum cost of the step before
            dp[i] = dp[i-1];

            for (const auto& p : flights) {
                dp[i][p[1]] = min(dp[i][p[1]], dp[i-1][p[0]] + p[2]);
            }
        }
        if (dp[k+1][dst] >= kInfCost) return -1;
        else return dp[k+1][dst];
    }
};