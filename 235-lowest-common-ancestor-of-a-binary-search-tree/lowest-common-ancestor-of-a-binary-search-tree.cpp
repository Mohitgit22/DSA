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
    TreeNode* ans = nullptr;

    void helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return ;

        while(root) {
            if((root -> val >= p->val && root->val <= q->val) 
                  || (root->val <= p->val && root->val >= q->val)) {
                ans = root;
                break;
            }

            if(root->val > p->val and root->val > q->val)
            root = root->left;
            if(root->val < p->val and root->val < q->val)
            root = root->right;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};