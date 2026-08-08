class Solution {
public:
    int dfs(int pos, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[pos]=true;
        int cnt = 1;

        for(auto &it: adj[pos]) if(!vis[it]) cnt+=dfs(it,adj,vis);

        return cnt;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                long long dx = bombs[i][0]-bombs[j][0];
                long long dy = bombs[i][1]-bombs[j][1];

                long long d = dx*dx + dy*dy;
                long long r2 = 1LL*bombs[i][2]*bombs[i][2];

                if(d<=r2) adj[i].push_back(j);
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            int cnt = dfs(i,adj,vis);
            ans = max(ans,cnt);
        }

        return ans;
    }
};