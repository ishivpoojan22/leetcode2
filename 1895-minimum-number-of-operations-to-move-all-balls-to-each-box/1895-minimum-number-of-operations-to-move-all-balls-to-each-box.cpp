class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);

        int count = 0, ops = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += ops;
            count += (boxes[i] == '1');
            ops += count;
        }

        count = 0, ops = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += ops;
            count += (boxes[i] == '1');
            ops += count;
        }

        return answer;
    }
};