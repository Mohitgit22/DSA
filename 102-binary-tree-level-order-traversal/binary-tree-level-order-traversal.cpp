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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        queue<TreeNode*> que;

        if(root == nullptr) return ans; 

        que.push(root);

        while(!que.empty()){

            int sz = que.size();
            vector<int> vec;
            for(int i = 0; i < sz; i++){
                TreeNode* curr = que.front();
                vec.push_back(curr->val);
                que.pop();

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
            }
            ans.push_back(vec);
        }

        return ans;
    }
};