class Solution {
public:
    int helper(vector<string>& a, int i, int m, int n, vector<vector<vector<int>>>& dp) {
        if (i == a.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];
        int z = count(a[i].begin(), a[i].end(), '0');
        int o = count(a[i].begin(), a[i].end(), '1');
        int notTake = helper(a, i + 1, m, n, dp);
        int take = 0;
        if (m >= z && n >= o) take = 1 + helper(a, i + 1, m - z, n - o, dp);
        return dp[i][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& a, int m, int n) {
        int sz = a.size();
        vector<vector<vector<int>>> dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(a, 0, m, n, dp);
    }
};
