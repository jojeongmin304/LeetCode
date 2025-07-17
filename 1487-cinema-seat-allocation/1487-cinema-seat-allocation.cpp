#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> rm;
        for (const auto& seat : reservedSeats ) {
            rm[seat[0]].insert(seat[1]);
        }

        int total = (n - rm.size()) * 2;
        
        for (const auto& [rowNum, reservedSet] : rm) {
            int count = 0;
            bool left = reservedSet.count(2) == 0 && reservedSet.count(3) == 0 && reservedSet.count(4) == 0 && reservedSet.count(5) == 0;
            bool middle = reservedSet.count(4) == 0 && reservedSet.count(5) == 0 && reservedSet.count(6) == 0 && reservedSet.count(7) == 0;
            bool right = reservedSet.count(6) == 0 && reservedSet.count(7) == 0 && reservedSet.count(8) == 0 && reservedSet.count(9) == 0;
            if (left && right) total += 2;
            else if (left || middle || right) total += 1;
        }
        
        return total;
    }
};