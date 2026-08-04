class Solution {
public:
    bool check(vector<int> &arr, int mini, int k)
    {
        int cnt = 1;
        int n = arr.size();

        int prev = arr[0];

        for(int i=1;i<n;i++)
        {
            if(arr[i]-prev>=mini)
            {
                cnt++;
                prev=arr[i];
            }
            if(cnt>=k) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int k) {
        int n = position.size();
        sort(position.begin(),position.end());

        int l = 1, h = position[n-1]-position[0];

        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(check(position,m,k)) l = m + 1;
            else h = m - 1;
        }
        return h;
    }
};