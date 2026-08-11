class Solution {
public:
    bool dfs(int node, int c, vector<int> &col, vector<vector<int>> adj)
    {
        col[node]=c;

        for(auto it: adj[node])
        {
            if(col[it]==-1)
            {
                if(!dfs(it,!c,col,adj)) return false;
            }
            else if(col[it]==c) return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // odd len cycle -- NOT BIPARTITE 
        // linear length graph - always bip.

        //dfs algo.
        vector<int> col(graph.size(),-1); //colors 0/1

        for(int i=0;i<graph.size();i++)
        {
            if(col[i]==-1)
            {
               if(!dfs(i,0,col,graph)) return false;
            }
        }
        return true;
    }
};