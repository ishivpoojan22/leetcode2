class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {

    int m = box.size();     
    int n = box[0].size();   

     
    vector<vector<char>> rotatedBox(n, vector<char>(m, '.'));

     
    for (int i = 0; i < m; i++) {
        int emptyPos = n - 1;  
        for (int j = n - 1; j >= 0; j--) {
            if (box[i][j] == '*') {
                
                emptyPos = j - 1;
            } else if (box[i][j] == '#') {
                 
                box[i][emptyPos] = '#';
                if (emptyPos != j) box[i][j] = '.';  
                emptyPos--;
            }
        }
    }

    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            rotatedBox[j][m - i - 1] = box[i][j];
        }
    }

    return rotatedBox;
}
        
    
};