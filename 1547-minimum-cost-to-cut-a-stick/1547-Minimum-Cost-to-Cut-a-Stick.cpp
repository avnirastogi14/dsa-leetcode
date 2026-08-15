class Solution {
public:

    int help(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if(i+1==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = INT_MAX;


        for(int x = i+1; x<j ;x++)
        {
            int l = help(i,x,cuts,dp);
            int r = help(x,j,cuts,dp);

            int cost = l + r + (cuts[j]-cuts[i]);

            ans = min(cost,ans);
        }

        return dp[i][j]=ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(),cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m,vector<int>(m,-1));

        int ans = help(0,m-1,cuts,dp);
        return ans;
    }
};