//problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 int solve(int index, int buy, vector<vector<int>>&dp,vector<int>& prices,int fee){
        if(index == prices.size()){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }

        int profit = 0;

        if(buy){
            int buyKaro = -prices[index] + solve(index+1,0,dp,prices,fee);
            int skipKaro = 0 + solve(index+1,1,dp,prices,fee);
            profit = max(buyKaro,skipKaro);
        }else{
            int sellKaro = prices[index] - fee + solve(index+1,1,dp,prices,fee);
            int skipKaro = 0 + solve(index+1,0,dp,prices,fee);
            profit = max(sellKaro,skipKaro);
        }

        return dp[index][buy] = profit;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,-1));
    return solve(0,1,dp,prices,fee);
}