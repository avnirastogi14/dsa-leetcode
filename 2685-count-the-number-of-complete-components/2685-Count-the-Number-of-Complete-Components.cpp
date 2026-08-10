class Solution {
public:

    bool trav(int pos, vector<vector<int>> &adj, vector<bool> &vis)
    {
        queue<int> q;
        q.push(pos);
        vis[pos]=true;
        int nod = 0, edg = 0;
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            nod++;
            edg+=adj[curr].size();

            for(auto &it: adj[curr])
            {
                if(!vis[it])
                {
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        edg/=2;
        return (edg==(nod*(nod-1)/2));
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(trav(i,adj,vis)) cnt++;
            }
        }
        return cnt;
    }
};