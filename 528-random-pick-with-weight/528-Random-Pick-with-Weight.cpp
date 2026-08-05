class Solution {
private:
    vector<int> sum;
    int tot=0;

public:
    Solution(vector<int>& w) {
        sum.push_back(w[0]);
        for(int i=1;i<w.size();i++) sum.push_back(sum[i-1]+w[i]);

        tot+=sum[w.size()-1];
    }
    
    int pickIndex() {
        int num = rand()%tot;

        int l = 0, h = sum.size()-1;

        while(l<h)
        {
            int m = l+(h-l)/2;

            if(sum[m]<=num) l = m+1;
            else h = m;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */