#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++)
            pq.push({nums[i], i});
        
        vector<int> output;

        for (int i = k-1; i < nums.size(); i++) {
            while(!pq.empty() && i - pq.top().second >= k)
                pq.pop();
            pq.push({nums[i], i});
            output.push_back(pq.top().first);
        }
        
        return output;
    }
};