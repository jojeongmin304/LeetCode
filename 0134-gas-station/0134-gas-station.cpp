class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int gasSum = 0;
        int costSum = 0;
        for (int i = 0; i < gas.size(); i++) {
            gasSum += gas[i];
            costSum += cost[i];
        }
        if (gasSum < costSum) return -1;

        int total = 0;
        int startPoint = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i];
            total -= cost[i];
            if (total < 0) {
                total = 0;
                startPoint = i + 1;
            }
        }
        return startPoint;
    }
};