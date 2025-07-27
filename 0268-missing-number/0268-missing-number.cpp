class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        int ans;
        long long sum1=0;
        for(int i=0; i<n; i++){
            sum=sum+nums[i];
        }
        sum1=n*(n+1)/2;

        return ans=sum1-sum;
    }
};