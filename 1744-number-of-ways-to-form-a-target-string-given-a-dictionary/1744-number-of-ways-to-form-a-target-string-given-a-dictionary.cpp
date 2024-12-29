class Solution {
public:
    int numWays(vector<string>& words, string target) {
        const int MOD = 1e9 + 7;
        int m = target.size();
        int n = words[0].size();

        vector<vector<long long>> freq(26, vector<long long>(n, 0));

        for (const string& word : words) {
            for (int j = 0; j < n; ++j) {
                freq[word[j] - 'a'][j]++;
            }
        }

        vector<long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int j = 0; j < n; ++j) {
            for (int i = m - 1; i >= 0; --i) {
                dp[i + 1] =
                    (dp[i + 1] + dp[i] * freq[target[i] - 'a'][j]) % MOD;
            }
        }

        return dp[m];
    }
};