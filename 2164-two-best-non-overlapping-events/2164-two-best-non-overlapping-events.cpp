class Solution {
public:
   bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    });

    int n = events.size();
    vector<int> maxValues(n, 0);
    int maxSum = 0;

    for (int i = n - 1; i >= 0; --i) {
        maxValues[i] = (i == n - 1) ? events[i][2] : max(maxValues[i + 1], events[i][2]);
    }

    for (int i = 0; i < n; ++i) {
        int currentValue = events[i][2];
        int left = i + 1, right = n - 1, bestIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > events[i][1]) {
                bestIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (bestIndex != -1) {
            currentValue += maxValues[bestIndex];
        }

        maxSum = max(maxSum, currentValue);
    }

    return maxSum;
    }
};