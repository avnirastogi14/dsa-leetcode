class Solution {
private:
    
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    bool unite(int u, int v)
    {
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return false;

        parent[pu] = pv;
        return true;
    }

public:
    vector<int> parent; // global par array.

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> par(n+1,0);

        vector<int> c1, c2;

        for(auto &it: edges)
        {
            int u = it[0]; //from
            int v = it[1]; //to

            if(par[v]==0) par[v]=u; // v has no parent, assign u
            else
            {
                // v already has a parent, so v now has 2 incoming edges
                // This can be:
                // 1. two parents only
                // 2. two parents + a cycle

                c1 = {par[v],v};
                c2 = {u,v}; //new value or the new competing edge
            }
        }

        parent.resize(n+1);
        // dsu parent arr

        for(int i=1;i<=n;i++) parent[i]=i;

        // dealing with the competing edge pair.
        // trying to avoid edge2

        for(auto &it: edges)
        {
            if(!c2.empty() && c2[0]==it[0] && c2[1]==it[1]) continue;

            if(!unite(it[0],it[1]))
            {
                if(!c1.empty()) return c1;
                return it;
            }
        }

        return c2; // case of 2 parents but no cycle.
    }
};

// O(n) due to path compression in amortized form.
// find is about O(𝛼(n)) 