#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        //weight, index greater
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available_servers;
        //availabe server queue initializtion
        for (int i = 0; i < servers.size(); i++) {available_servers.push({servers[i], i});}

        //pair: {finishTime, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy_servers;
        
        vector<int> output(tasks.size());
        int currentTime = 0;

        for (int i = 0; i < tasks.size(); i++) {
            currentTime = max(i, currentTime);
            //현재시간까지 작업이끝난서버들을 available로 이동
            while(!busy_servers.empty() && busy_servers.top().first <= currentTime) {
                int serverIndex = busy_servers.top().second;
                busy_servers.pop();
                available_servers.push({servers[serverIndex], serverIndex});
            }
            if (available_servers.empty()) {
                currentTime = busy_servers.top().first;
                while (!busy_servers.empty() && busy_servers.top().first <= currentTime) {
                    int serverIndex = busy_servers.top().second;
                    busy_servers.pop();
                    available_servers.push({servers[serverIndex], serverIndex});
                }
            }
            //now there must be a available server
            pair<int, int> best_server = available_servers.top();
            available_servers.pop();

            int serverIndex = best_server.second;
            output[i] = serverIndex;

            int finishTime = currentTime + tasks[i];
            busy_servers.push({finishTime, serverIndex});
        }
        return output;
    }
};