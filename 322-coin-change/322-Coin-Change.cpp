class Solution {
public:

    int help(vector<int> &coins, int pos, int X, vector<vector<int>> &dp)
    {
        // R E C U R S I O N
        if(pos==0)
        {
            if(X%coins[pos]==0) return X/coins[pos];

            return 1e9;
        }

        // int nt= help(coins,pos-1,X);

        // int t = 1e9;
        // if(coins[pos]<=X)
        // {
        //     t = 1 + help(coins,pos,X-coins[pos]);
        // }

        // return min(t,nt);

        // M E M O I Z A T I O N

        if(dp[pos][X]!=-1) return dp[pos][X];

        int nt = help(coins,pos-1,X,dp);
        int t = 1e9;
        if(X>=coins[pos]) t = 1+help(coins,pos,X-coins[pos],dp);

        return dp[pos][X]=min(t,nt);
    }

    int coinChange(vector<int>& coins, int amount) {
        // return (help(coins,coins.size()-1,amount)==1e9)?-1:help(coins,coins.size()-1,amount);
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));

        int ans = help(coins,n-1,amount,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};