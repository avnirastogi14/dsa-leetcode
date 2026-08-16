class Solution {
public:

    int help(int curr ,int last, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(curr==nums.size()) return 0;

        if(dp[curr][last+1]!=-1) return dp[curr][last+1]
;

        int nt = help(curr+1,last,nums,dp);
        int t = 0;
        if(last==-1 || nums[curr]>nums[last]) 
        {
            t = 1 + help(curr+1,curr, nums,dp);
        }

        return dp[curr][last+1] = max(t,nt);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (n+1,-1));

        return help(0,-1,nums,dp);   
    }
};