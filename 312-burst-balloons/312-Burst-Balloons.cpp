class Solution {
public:

    /*
    RECURSION CALL basic

    think of every balloon as last balloon -- all split cases 

    int help(i, j, nums)
    {
        if(i+1==j) return 0;

        ans = 0;

        for(int x=i+1;x<j;x++)
        {
            int l= help(i,x,nums);
            int r= help(x,j,nums);

            int val = nums[i]*nums[x]*nums[j];
            int tot = l + r + val;

            ans = max(ans,tot);
        }

        return ans;
    }
    */

    // memoized version

    int help(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        // dp table will hold the cost values when we burst balloons

        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0;
        for(int x=i+1;x<j;x++)
        {
            int l = help(i,x,nums,dp);
            int r = help(x,j,nums,dp);

            int val = nums[i]*nums[j]*nums[x];
            ans = max(ans,l+r+val);
        }

        return dp[i][j]=ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

        return help(0,n-1,nums,dp);
    }
};