class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1, suff = 1;
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++)
        {
            // restart cases
            if(pref==0) pref=1;
            if(suff==0) suff=1;

            pref*=nums[i];
            suff*=nums[n-i-1];

            ans = max(ans,max(pref,suff));
        }

        return ans;
    }
};