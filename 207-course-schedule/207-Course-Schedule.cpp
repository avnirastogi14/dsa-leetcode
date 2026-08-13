class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        int n =numCourses;
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);

        for(auto &it: prereq)
        {
            adj[it[1]].push_back(it[0]);
            indeg[it[0]]++;
        }

        int c= 0;
        queue<int> q;
        for(int i=0;i<n;i++) if(!indeg[i]) q.push(i);

        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            c++;

            for(auto it: adj[curr]) if(--indeg[it]==0) q.push(it);
        }
        return c==n;
    }
};