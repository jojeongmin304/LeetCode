class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int total = 0;

        int totalGas = 0;
        int totalCost = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) return -1;

        for (int i = 0; i < gas.size(); i++) {
            total += gas[i]; //기름충전

            if (total - cost[i] < 0) {
                if (i + 1 >= gas.size()) return -1;
                start = i + 1;
                total = 0;
            }
            else {
                total -= cost[i];
            }
        }
        return start;
    }
};