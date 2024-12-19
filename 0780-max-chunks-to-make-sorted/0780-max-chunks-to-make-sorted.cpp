class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
         int n=arr.size();
        int a=0, diff=0;
        for(int i=0; i<n; i++){
            diff+=arr[i]-i;
            a+=(diff==0);
        }
        return a;
    }
        
    
};