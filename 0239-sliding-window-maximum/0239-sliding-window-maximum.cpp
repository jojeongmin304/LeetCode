#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k-1; i++)
            pq.push({nums[i], i});
        for (int i = k-1; i < nums.size(); i++) {
            while((!pq.empty() && i - pq.top().second >= k)) {
                        pq.pop();
            }
            pq.push({nums[i], i});
            output.push_back(pq.top().first);
        }
        return output;
    }
};