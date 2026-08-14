class Solution {
public:

/*
RECURSIVE PSEUDO CODE - 

    bool func helper(int sum, int pos, nums)
    {
        if(pos==0) return nums[pos]==sum;
        if(sum==0) return true;

        bool take = false;
        bool ntk = helper(sum, pos-1, nums);
        if(nums[pos]<=sum) take = helper(sum-nums[pos],pos-1,nums);

        return take || ntk;
    }
*/

    /*
    bool helper(vector<int> &nums, int X, vector<vector<int>> &dp, int pos)
    {
        if(pos==0) return nums[pos]==X;
        if(X==0) return true;

        // choice diagram : 
        bool nt = helper(nums,X,dp,pos-1);
        bool t = false;
        if(nums[pos]<=X) t = helper(nums,X-nums[pos],dp,pos-1);

        return t || nt;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i: nums) sum+=i;

        if(sum%2==0)
        {   
            vector<vector<int>> dp(nums.size()+1, vector<int>(sum+1,0));
            bool ans = helper(nums,sum/2, dp, nums.size()-1);
            return ans;
        }
        return false;
    }
    */

    bool help(vector<int> &nums, int X)
    {
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(X+1,false));


        for(int i=0;i<=n;i++)
        {
            dp[i][0]=true;
        }
        // initialisation done.

        // filling the dp table
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=X;j++)
            {
                // conditional changes.

                bool nt = dp[i-1][j];

                bool t = false;
                if(nums[i-1]<=j)
                {
                    t = dp[i-1][j-nums[i-1]];
                }

                dp[i][j]= t || nt;
            }
        }
        return dp[n][X];
    }

    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for(int i: nums) sum+=i;

        if(sum%2==0)
        {
            bool ans = help(nums,sum/2);
            return ans;
        }
        return false;
    }
};