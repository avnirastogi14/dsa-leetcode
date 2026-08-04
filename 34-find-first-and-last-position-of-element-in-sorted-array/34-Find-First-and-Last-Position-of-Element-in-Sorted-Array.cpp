class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int X) {
        int n = nums.size();
        int st = -1, end = -1;

        int l = 0, h = n - 1;

        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(nums[m]==X)
            {
                st = m;
                h = m - 1; // check in left of the mid for any prev occurrence
            }
            else if(nums[m]>X) h = m-1;
            else l = m+1;
        }

        l = 0, h = n-1;
        while(l<=h)
        {
            int m = l + (h-l)/2;

            if(nums[m]==X)
            {
                end = m;
                l = m+1;
            }
            else if(nums[m]>X) h = m-1;
            else l = m+1;
        }
        
        return {st, end};
    }
};