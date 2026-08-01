class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n =nums.size();
        int l = 0, r = 0;
        int maxi = INT_MIN;
        int val = 0;
        while(r<n)
        {
            while(val&nums[r]) // true ie not zero
            {
                // shrink
                val^=nums[l];
                l++;
            }

            val|= nums[r]; //mask
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};