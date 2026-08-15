class Solution {
public:
    int help(int i, int X, vector<int>& S, vector<vector<int>>& dp)
    {
        if (i == 0)
        {
            if(S[0]<=X) return S[0];
            else return 0;
        }

        if (dp[i][X]!=-1) return dp[i][X];

        int nt=help(i-1,X,S,dp);
        int t=0;
        if(S[i]<=X) t=S[i]+help(i-1,X-S[i],S,dp);

        return dp[i][X]=max(t,nt);
    }

    int lastStoneWeightII(vector<int>& S) {
        int tot=accumulate(S.begin(),S.end(),0);
        int X=tot/2;
        int n=S.size();

        vector<vector<int>> dp(n, vector<int>(X+1,-1));
        int ans= help(n-1,X,S,dp);
        return tot-2*ans;
    }
};
