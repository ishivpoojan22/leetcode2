class Solution {
public:
    bool canDivide(const vector<int>& nums, int maxPenalty, int maxOperations) {
        int operations = 0;
        for (int balls : nums) {
            if (balls > maxPenalty) {
                operations += (balls - 1) / maxPenalty;
            }
            if (operations > maxOperations) {
                return false;
            }
        }
        return true;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};