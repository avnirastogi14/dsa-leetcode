class Solution {
public:

    // int help(int pos, int buy, int k, vector<int> &p)
    // {
    //     if(pos==p.size() || k==0) return 0;

    //     if(buy)
    //     {
    //         int nt = help(pos+1,1,k,p);
    //         int t = help(pos+1,0,k,p) - p[pos]; // balance reduces

    //         return max(t,nt);
    //     }
    //     else
    //     {
    //         int nt = help(pos+1,0,k,p);
    //         int t = help(pos+1,1,k-1,p) + p[pos]; // balance increases

    //         return max(t,nt);
    //     }
    // }

    int help(int pos, int buy, int k, vector<int> &p,vector<vector<vector<int>>> &dp)
    {
        if(pos==p.size() || k==0) return 0;
        if(dp[pos][buy][k] != -1) return dp[pos][buy][k];
        if(buy)
        {
            int nt = help(pos+1,1,k,p,dp);
            int t = help(pos+1,0,k,p,dp) - p[pos]; // balance reduces

            return dp[pos][buy][k] = max(t,nt);
        }
        else
        {
            int nt = help(pos+1,0,k,p,dp);
            int t = help(pos+1,1,k-1,p,dp) + p[pos]; // balance increases

            return dp[pos][buy][k] = max(t,nt);
        }
    }

    int maxProfit(vector<int>& prices) {
        // 1 transaction after sell done
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3, -1)));
        return help(0,1,2,prices,dp);
    }
};