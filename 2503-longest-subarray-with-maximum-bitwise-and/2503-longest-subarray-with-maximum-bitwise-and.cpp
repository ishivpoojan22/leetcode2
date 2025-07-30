class Solution {
public:
    int longestSubarray(vector<int>& nums) {
  int maxi = nums[0];
        int bestLength = 0;
        int currentLength = 0;

        for (int num : nums) {
            if (num == maxi) {
                currentLength++;                  
            } else if (num > maxi) {              
                maxi = num;                       
                currentLength = 1;                
                bestLength = 1;                  
            } else {
                currentLength = 0;               
            }
            bestLength = max(bestLength, currentLength);
        }
        return bestLength;
    }
};