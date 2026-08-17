/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int,int>>> q; // {Node,{HD,level}}

        q.push({root,{0,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            TreeNode* node = it.first;

            int hd = it.second.first;
            int lvl = it.second.second;

            mp[hd][lvl].insert(node->val);

            if(node->left) q.push({node->left,{hd-1,lvl+1}});
            if(node->right) q.push({node->right,{hd+1,lvl+1}});
        }


        vector<vector<int>> ans;
        for(auto &it: mp)
        {
            vector<int> temp;
            for(auto & lvl: it.second)
            {
                for(auto &val: lvl.second)
                {
                    temp.push_back(val);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};