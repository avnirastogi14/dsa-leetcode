class Solution {
public:
    long long check(vector<int> &piles, int val)
    {
        long long tot = 0;
        for(int i=0;i<piles.size();i++) tot+=ceil((double)piles[i]/val);
        return tot;
    }

    int minEatingSpeed(vector<int>& piles, int X) {
        int n = piles.size();
        int l = 1, h = *max_element(piles.begin(),piles.end());

        int ans = h;

        while(l<=h)
        {
            int m = l + (h-l)/2;
            if(check(piles,m)<=X)
            {
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};