class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis, vector<vector<int>> &adj, vector<int> &flag)
    {
        vis[node]=1;
        pathVis[node]=1;

        for(auto &it: adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it,vis,pathVis,adj,flag)) return true;
            }
            else if(pathVis[it]) return true;
        }
        flag[node]=2;
        pathVis[node]=0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> flag(V,0);
        vector<int> ans;

        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,pathVis,graph,flag);
            }
        }

        for(int i=0;i<V;i++)
        {
            if(flag[i]==2) ans.push_back(i);
        }

        return ans;
    }
};