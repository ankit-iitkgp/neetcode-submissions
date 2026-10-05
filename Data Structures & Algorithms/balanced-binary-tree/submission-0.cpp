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
    bool isBalanced(TreeNode* root) {
        return isBalancedUtil(root).first;
    }

    pair<bool, int> isBalancedUtil(TreeNode* root) {
        if(root == NULL) return make_pair(true, 0);
        auto left = isBalancedUtil(root->left);
        auto right = isBalancedUtil(root->right);

        bool bal = true;
        if(abs(left.second - right.second) > 1) bal = false;
        else bal = left.first && right.first;
        int h = 1+ max(left.second, right.second);
        return make_pair(bal, h);
    }
};
