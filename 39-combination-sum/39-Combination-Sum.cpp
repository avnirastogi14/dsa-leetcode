class Solution {
public:

    void solve(int index,
               vector<int>& candidates,
               int target,
               vector<int>& current,
               vector<vector<int>>& ans)
    {
        // Target reached.
        if(target == 0)
        {
            ans.push_back(current);
            return;
        }
        if(index == candidates.size())return;

        // remaining target, so we cannot take it.
        if(candidates[index] > target)
        {
            solve(index + 1, candidates,target, current, ans);return;
        }

        current.push_back(candidates[index]);

        solve(index,candidates,target - candidates[index],current,ans);

        current.pop_back();
        solve(index + 1,candidates,target,current,ans);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates,int target)
    {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, candidates, target, current, ans);
        return ans;
    }
};