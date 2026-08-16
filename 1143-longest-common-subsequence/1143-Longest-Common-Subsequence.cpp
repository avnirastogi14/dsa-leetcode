class Solution {
public:

    // int help(int i, int j, string &s1, string &s2)
    // {
    //     if(i<0 || j<0) return 0;

    //     if(s1[i]==s2[j])
    //     {
    //         //match ho gya
    //         return 1 + help(i-1,j-1,s1,s2);
    //     }

    //     int way1= help(i-1,j,s1,s2);
    //     int way2= help(i,j-1,s1,s2);

    //     return max(way1,way2);
    // }

    int longestCommonSubsequence(string s1, string s2) {
        // return help(s1.size()-1,s2.size()-1,s1,s2);
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));


        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};