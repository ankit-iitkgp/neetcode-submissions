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
        queue<TreeNode*> tree_q;
        vector<vector<int>> result;
        if(!root) return result;
        tree_q.push(root);
        TreeNode* node;
        while(!tree_q.empty()) {
            int n = tree_q.size();
            vector<int> temp;
            for(int i=0; i<n; i++) {
                node = tree_q.front();
                temp.push_back(node->val);
                tree_q.pop();
                if(node->left) tree_q.push(node->left);
                if(node->right) tree_q.push(node->right);
            }
            result.push_back(temp);
            temp.clear();
        }
        return result;
    }
};
