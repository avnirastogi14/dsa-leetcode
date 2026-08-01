class Solution {
public:
    int search(vector<int>& nums, int X) {
        int l = 0, h = nums.size()-1;

        while(l<=h)
        {
            int m = (l+h)/2;

            if(nums[m]==X) return m;
            else
            {
                //left sorted:
                if(nums[l]<=nums[m])
                {
                    // if left half has X ==> X belongs to [nums[l],nums[m]]
                    if(X>=nums[l] && X<=nums[m]) h = m-1;
                    else l = m+1;
                }
                // right sorted:
                else
                {
                    // X belongs to [nums[m],nums[h]]
                    if(X>=nums[m] && X<=nums[h]) l = m+1;
                    else h = m-1;
                }
            }
        }
        return -1;
    }
};