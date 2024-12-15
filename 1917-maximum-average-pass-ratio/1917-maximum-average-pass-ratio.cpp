class Solution {
public:
    double improvement(int pass, int total) {
        return (double)(pass + 1) / (total + 1) - (double)pass / total;
    }

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>> pq;
        for (auto& c : classes) {
            pq.push({improvement(c[0], c[1]), {c[0], c[1]}});
        }
        while (extraStudents-- > 0) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            pass++;
            total++;
            pq.push({improvement(pass, total), {pass, total}});
        }
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int pass = top.second.first;
            int total = top.second.second;
            totalRatio += (double)pass / total;
        }
        return totalRatio / classes.size();
    }
};