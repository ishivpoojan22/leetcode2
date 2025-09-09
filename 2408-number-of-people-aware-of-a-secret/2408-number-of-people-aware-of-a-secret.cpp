class Solution {
public:
int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {

        vector<long long int> t(n + 1, 0);
        long long int shear = 0;
        t[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (i - delay >= 1)
                shear = (shear + t[i - delay]) % mod;
            if (i - forget >= 1)
                shear = 1LL * (shear - t[i - forget] + mod) % mod;
            t[i] = shear;
        }
        int ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1)
                ans = (ans + t[i]) % mod;
        }
        return ans;
    }
};