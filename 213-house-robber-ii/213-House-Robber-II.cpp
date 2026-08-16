class Solution {
public:

    int help(int pos, int l, vector<int> nums,vector<int> &dp)
    {
        // if l == 1 we want to exclude the first house
        // if l == 0 we want to exclude the last house

        if(pos<l) return 0;
        if(pos==l) return nums[pos];

        if(dp[pos]!=-1) return dp[pos];

        int nt = help(pos-1,l,nums,dp);
        int t = nums[pos] + help(pos-2,l,nums,dp);

        return dp[pos] = max(t,nt);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        if(n==1) return nums[0];

        int way1 = help(n-1,1,nums,dp1);
        int way2 = help(n-2,0,nums,dp2);

        return max(way1,way2);   
    }
};