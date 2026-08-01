class Solution {
public:

    int help(int st, int end, vector<int> &arr)
    {
        if(st==end) return arr[st];

        int pick = arr[st] - help(st+1, end, arr);
        int notp = arr[end] - help(st,end-1,arr);

        return max(pick,notp);
    }

    bool predictTheWinner(vector<int>& nums) {
        return help(0,nums.size()-1,nums)>=0;
    }
};