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
private:
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        int maxSumAtRoot = maxUtil(root);
        return max(maxSum, maxSumAtRoot);
    }

    int maxUtil(TreeNode *node) {
        if(!node) return 0;
        int leftMax = maxUtil(node->left);
        int rightMax = maxUtil(node->right);
        int maxBranch = max(leftMax, rightMax);
        int maxAtNode = node->val;
        if(maxBranch > 0) maxAtNode = max(maxBranch+(node->val), leftMax+rightMax+(node->val));
        maxSum = max(maxSum, maxAtNode);
        int utilMax = max(node->val, node->val + maxBranch);
        return utilMax;
    }
};
