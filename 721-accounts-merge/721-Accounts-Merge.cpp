class Solution {
private:
    int find(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }

    void unite(int u,int v)
    {
        int pu = find(u);
        int pv = find(v);

        if(pu==pv) return;

        parent[pu]=pv;
    }

public:

    vector<int> parent;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;

        unordered_map<string,int> mp; 
        // to record mails as the node (component parent) and the emails as the children node.
        // useful when merging.
            // for every mail, if mail seen before?
                // yes:
                    // union accounts
                    // dsu: group email by roots.

                // no:
                    // remember account
        // sort and return the emails!! (ATQ)

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++) // X emails per name
            {
                // j = 1 to X-1 since email starts at index1
                string mail = accounts[i][j];

                if(mp.find(mail)==mp.end()) mp[mail]=i; // mail !found --> STORE
                else
                {
                    unite(i,mp[mail]);
                }
            }
        }

        // grouping the components under common names if same person

        unordered_map<int,vector<string>> grouped;

        for(auto &it: mp)
        {
            string mail = it.first;
            int id = it.second; // node number for component node simulation

            int par = find(id); // for parent logic

            grouped[par].push_back(mail); // push into the same parent node if same emails
        }

        vector<vector<string>> ans;

        for(auto &it: grouped)
        {
            int par = it.first;
            sort(it.second.begin(), it.second.end()); // sorting mails

            vector<string> curr;
            curr.push_back(accounts[par][0]); // pushing the name
            for(auto &mail: it.second) curr.push_back(mail);

            ans.push_back(curr);
        }
        return ans; // final ans arr with name, email(S) per person

    }
};