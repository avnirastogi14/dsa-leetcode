class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prereq){
        int n = numCourses;
        vector<int> indeg(n);
        vector<vector<int>> adj(n);

        for(auto it: prereq)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++) if(!indeg[i]) q.push(i);

        vector<int> ans;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(auto it: adj[curr])
            {
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        if(n==ans.size()) return ans;
        return {};
    }
};