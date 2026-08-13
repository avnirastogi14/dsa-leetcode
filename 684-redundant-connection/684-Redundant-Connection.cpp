class Solution {
private:
    int findParent(int node, vector<int> &par)
    {
        if(node==par[node]) return node;
        return par[node]=findParent(par[node],par);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1);

        for(int i=0;i<=n;i++) par[i]=i;

        for(auto &it: edges)
        {
            int p1 = findParent(it[0],par);
            int p2 = findParent(it[1],par);

            if(p1==p2) return it;
            par[p2]=p1;
        }
        return {-1,-1};
    }
};