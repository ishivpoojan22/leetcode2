class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        string target = "123450";

        string start;
        for (const auto& row : board) {
            for (int cell : row) {
                start += to_string(cell);
            }
        }

        if (start == target)
            return 0;

        vector<vector<int>> neighbors = {{1, 3}, {0, 2, 4}, {1, 5},
                                         {0, 4}, {1, 3, 5}, {2, 4}};

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({start, 0});
        visited.insert(start);

        while (!q.empty()) {
            auto [current, moves] = q.front();
            q.pop();

            int zeroPos = current.find('0');

            for (int neighbor : neighbors[zeroPos]) {
                string next = current;
                swap(next[zeroPos], next[neighbor]);

                if (next == target)
                    return moves + 1;

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push({next, moves + 1});
                }
            }
        }

        return -1;
    }
};