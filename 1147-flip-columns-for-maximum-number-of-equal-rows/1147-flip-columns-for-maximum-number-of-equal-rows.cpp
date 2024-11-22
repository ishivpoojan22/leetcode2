class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> rowCount;

    for (const auto& row : matrix) {
        string pattern;
        string flippedPattern;

         
        for (int val : row) {
            if (row[0] == 0) {
                pattern += (val == 0) ? '0' : '1';
                flippedPattern += (val == 0) ? '1' : '0';
            } else {
                pattern += (val == 1) ? '0' : '1';
                flippedPattern += (val == 1) ? '1' : '0';
            }
        }

         
        rowCount[pattern]++;
    }

     
    int maxRows = 0;
    for (const auto& [key, count] : rowCount) {
        maxRows = max(maxRows, count);
    }

    return maxRows;
}
        

};