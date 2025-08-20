class Solution {
public:

    // void findMaxprofit(vector<int>& prices, int i, int& minPrice, int& maxProfit){

         
    //     if( i == prices.size())
    //         return;

        
    //     if(prices[i] < minPrice)
    //         minPrice = prices[i];

    //     if((prices[i] - minPrice) > maxProfit)
    //         maxProfit = prices[i] - minPrice;


         
    //     findMaxprofit(prices, i+1, minPrice, maxProfit);  
    // }
    int maxProfit(vector<int>& prices) {

        // int minPrice = INT_MAX;
        // int maxProfit = INT_MIN;

        // findMaxprofit(prices, 0, minPrice, maxProfit);

        // return maxProfit;

        int minPrice = INT_MAX;
        int maxPrice = INT_MIN;

        int i=0;

        while(i < prices.size()){

            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            if((prices[i] - minPrice) > maxPrice){
                maxPrice = prices[i] - minPrice;
            }
            i++;
        }
        return  maxPrice;
        
    }
};