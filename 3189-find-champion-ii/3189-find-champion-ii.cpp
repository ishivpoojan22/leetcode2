class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {

        vector<int> in_degree(n, 0);
        vector<vector<int>> graph(n);

     
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        in_degree[v]++;
    }

     
    int candidate = -1;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            if (candidate != -1) {
                
                return -1;
            }
            candidate = i;
        }
    }

    if (candidate == -1) {
         
        return -1;
    }

     
    queue<int> q;
    unordered_set<int> visited;

    q.push(candidate);
    visited.insert(candidate);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

     
    if (visited.size() != n) {
        return -1;
    }

    return candidate;
}
        
    
};