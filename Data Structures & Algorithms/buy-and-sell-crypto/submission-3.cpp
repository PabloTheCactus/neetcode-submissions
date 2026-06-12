class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxdifference = 0;
        int min = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[min] < prices[i+1]){
                if(maxdifference < prices[i+1] - prices[min]) {
                maxdifference = prices[i+1] - prices[min];
                }
                if(prices[min] > prices[i]){min = i;}
            }
            else if(prices[min] >= prices[i+1]){
                min = i + 1;
            }
        }
        return maxdifference;
    }
};
