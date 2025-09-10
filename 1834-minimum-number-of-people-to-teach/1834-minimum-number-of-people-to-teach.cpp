class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size();

        
        vector<vector<bool>> knows(m + 1, vector<bool>(n + 1, false));
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                knows[i + 1][l] = true;  
            }
        }

 
        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canTalk = false;
            for (int l = 1; l <= n; l++) {
                if (knows[u][l] && knows[v][l]) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }

 
        if (needTeach.empty())
            return 0;

 
        int ans = INT_MAX;
        for (int l = 1; l <= n; l++) {
            int count = 0;
            for (int user : needTeach) {
                if (knows[user][l])
                    count++;
            }
            ans = min(ans, (int)needTeach.size() - count);
        }

        return ans;
    }
};