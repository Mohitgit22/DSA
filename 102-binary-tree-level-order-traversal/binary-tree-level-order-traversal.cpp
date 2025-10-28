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
        if(root == nullptr) return {};

        queue<TreeNode*> que;
        que.push(root);

        vector<vector<int>> ans;
        while(!que.empty()){
            
            int n = que.size();
            vector<int> vec;
            while(n > 0){
                TreeNode* front = que.front();
                vec.push_back(front->val);
                que.pop();
                n--;
           
                if(front->left) que.push(front->left);
                if(front->right) que.push(front->right);
            }
            ans.push_back(vec);
            // vec.clear();
        }
        return ans;
    }
};