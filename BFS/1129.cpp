#include "inc.h"

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> next(2, vector<vector<int>>(n));
        for (auto &e : redEdges) {
            next[0][e[0]].push_back(e[1]);
        }
        for (auto &e : blueEdges) {
            next[1][e[0]].push_back(e[1]);
        }

        vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        dist[0][0] = 0;
        dist[1][0] = 0;
        q.push({0, 0});
        q.push({1, 0});
        while (!q.empty()) {
            auto v = q.front();
            q.pop();
            for (auto &e : next[1 - v.first][v.second]) {
                if (dist[1 - v.first][e] != INT_MAX) {
                    continue;
                }
                dist[1 - v.first][e] = dist[v.first][v.second] + 1;
                q.push({1 - v.first, e});
            }
        }
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = min(dist[0][i], dist[1][i]);
            if (answer[i] == INT_MAX) {
                answer[i] = -1;
            }
        }
        return answer;
    }
};

int main()
{
    vector<vector<int>> a = {{0,1},{1,2}}, b = {};
    Solution sl;
    sl.shortestAlternatingPaths(3, a, b);
    return 0;
}