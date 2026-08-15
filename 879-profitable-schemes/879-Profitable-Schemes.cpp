const int MOD = 1e9 + 7;
class Solution {
public:

    int help(vector<vector<vector<int>>> &dp, int P, int PPL, vector<int> &prof, int pos, vector<int> &grp, int curr)
    {
        if(pos<0) return curr>=P?1:0;

        if(dp[pos][PPL][curr]!=-1) return dp[pos][PPL][curr];

        int ntk = help(dp,P,PPL,prof,pos-1,grp,curr);
        int tk = 0;

        if(grp[pos]<=PPL)
        {
            int nP = min(P,curr+prof[pos]);
            tk = help(dp,P,PPL-grp[pos],prof,pos-1,grp,nP);
        }

        return dp[pos][PPL][curr]= (tk+ntk)%MOD;


    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(profit.size(),vector<vector<int>>(n+1,vector<int>(minProfit+1, -1)));

        // dp[pos][ppl][prof]

        int ans = help(dp,minProfit,n,profit,profit.size()-1,group,0);

        return ans;
    }
};