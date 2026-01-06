class Solution {
public:
    int maxProfit(vector<int>& prices) { // [7,1,5,3,6,4]
        // int buy = prices[0];  // 7
        // int profit = 0;
        // for(int i=1; i<prices.size(); i++){
        //     if(buy > prices[i]){ 
        //         buy = prices[i]; // 1,1,1,1,1
        //     }
        //     profit = max(profit , prices[i] - buy); // 0,4,4,5,5
        // } 
        // return profit;

        int low = prices[0];
        int maxProfit = 0;
        for(int i=1; i<prices.size(); i++){
            if(low > prices[i]){
                low = prices[i];
            }
            int profit = prices[i] - low;
            maxProfit = max(maxProfit , profit);
        }

        return maxProfit;
    }
};