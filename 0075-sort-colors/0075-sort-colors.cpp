class Solution {
public:
    void sortColors(vector<int>& nums) {

        // sort(nums.begin(), nums.end());

    //     int numZero = 0;
    //     int numOne = 0;
    //     int numTwo = 0;

    //     for(int i=0;i<nums.size();i++){
    //         if(nums[i] == 0){
    //         numZero++;
    //     }
    //     else if(nums[i] == 1){
    //         numOne++;
    //     }
    //     else{
    //         numTwo++;
    //     }

    //     }

    // }



    int l=0,m=0,h=nums.size()-1;
    while(m<=h){
        //    for(int i=0;i<nums.size();i++){
        if(nums[m]==0){
            swap(nums[l],nums[m]);
            l++;
            m++;
        }
        else if(nums[m]==1){
            m++;
        }
        else{
            swap(nums[m],nums[h]);
            h--;
        }
    // }

    }
 
    
    }
};