class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int increment = (direction == 1) ? 1 : -1;
            diff[start] += increment;
            diff[end + 1] -= increment;
        }

        int cumulative = 0;
        for (int i = 0; i < n; i++) {
            cumulative += diff[i];
            int shift_value = (s[i] - 'a' + cumulative % 26 + 26) % 26;
            s[i] = 'a' + shift_value;
        }

        return s;
    }
};