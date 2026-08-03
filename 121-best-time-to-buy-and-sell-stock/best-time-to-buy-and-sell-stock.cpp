class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi =INT_MIN ;
        int ans = 0;

        for(int i =prices.size()-1 ; i>=0 ; i--){
            if(maxi > prices[i]){
                ans = max(ans , maxi-prices[i]);
            }else{
                maxi = prices[i];
            }
        }
        return ans ;
    }
};