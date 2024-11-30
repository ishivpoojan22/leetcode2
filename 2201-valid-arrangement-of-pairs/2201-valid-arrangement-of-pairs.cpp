class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> inDegree, outDegree;

        for (auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        int startNode = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outDegree[node] - inDegree[node] == 1) {
                startNode = node;
                break;
            }
        }

        stack<int> stack;
        vector<int> path;
        stack.push(startNode);

        while (!stack.empty()) {
            int node = stack.top();
            if (!graph[node].empty()) {
                int next = graph[node].back();
                graph[node].pop_back();
                stack.push(next);
            } else {
                path.push_back(node);
                stack.pop();
            }
        }

        reverse(path.begin(), path.end());

        unordered_map<int, int> index;
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }
};