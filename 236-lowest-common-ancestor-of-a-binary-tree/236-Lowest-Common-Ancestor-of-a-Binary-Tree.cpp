/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // for any node -- 3 cases:
        // itself is ans
        // p or q in diff subtrees
        // in same subtrees

        if(!root) return nullptr;

        if(root==p || root==q) return root;
        
        TreeNode* l = lowestCommonAncestor(root->left,p,q);
        TreeNode* r = lowestCommonAncestor(root->right,p,q);

        if(l!=nullptr && r!=nullptr) // both sides have a target node 
            return root;

        if(l!=nullptr) return l;
        return r;
    }
};