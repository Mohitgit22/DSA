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
    TreeNode* lca(TreeNode* root,unordered_map<int,int>& mp ,int maxd){
        if(!root) return root;

       if(mp[root->val] == maxd)
       return root;

        TreeNode* left = lca(root->left, mp, maxd);
        TreeNode* right = lca(root->right, mp, maxd);

        if(left!=nullptr and right!=nullptr)
        return root;

        if(left) return left;
        else 
        return right;
    }

    void depth(TreeNode* root, unordered_map<int,int>& mp , int currdepth, int& maxd){
        if(!root ) return ;

        mp[root->val] = currdepth;
        maxd = max(maxd, currdepth);
        depth(root->left, mp, currdepth+1, maxd);
        depth(root->right, mp, currdepth+1, maxd);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxd = 0;
        depth(root, mp, 0, maxd);
        cout<<maxd;
        return lca(root, mp, maxd);
    }
};