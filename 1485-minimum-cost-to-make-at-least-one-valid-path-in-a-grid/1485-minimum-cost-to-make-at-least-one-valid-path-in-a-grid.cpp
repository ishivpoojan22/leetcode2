class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        auto push = [&](int x, int y, int c) {
            if (x >= 0 && x < m && y >= 0 && y < n && cost[x][y] > c) {
                cost[x][y] = c;
                if (c == 0) {
                    dq.emplace_front(x, y);
                } else {
                    dq.emplace_back(x, y);
                }
            }
        };

        dq.emplace_back(0, 0);
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + directions[i][0];
                int ny = y + directions[i][1];
                push(nx, ny, cost[x][y] + (grid[x][y] != i + 1));
            }
        }

        return cost[m - 1][n - 1];
    }
};