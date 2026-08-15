class Solution {
public:

    int help(vector<vector<vector<int>>> &dp, int pos, int zc, int oc, vector<string> &ss)
    {
        if(pos==0) return 0;
        if(dp[pos][zc][oc]!=-1) return dp[pos][zc][oc];

        int z = count(ss[pos-1].begin(),ss[pos-1].end(),'0');
        int o = count(ss[pos-1].begin(),ss[pos-1].end(),'1');

        int nt = help(dp,pos-1,zc,oc,ss);

        int t = 0;
        if(z<=zc && o<=oc) t = 1+help(dp,pos-1,zc-z,oc-o,ss);

        return dp[pos][zc][oc]=max(t,nt);
    }

    int findMaxForm(vector<string>& strs, int zc, int oc) {
        int ans = 0;
        int n = strs.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(zc+1,vector<int>(oc+1,-1)));
        ans = help(dp,n,zc,oc,strs);

        return ans;
    }
};