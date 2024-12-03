class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int n = s.size();
        int spaceIndex = 0, spacesSize = spaces.size();

        for (int i = 0; i < n; ++i) {
            if (spaceIndex < spacesSize && i == spaces[spaceIndex]) {
                result += ' ';
                spaceIndex++;
            }
            result += s[i];
        }
        return result;
    }
};