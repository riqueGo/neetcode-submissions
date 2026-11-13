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
    int ans = -1001;

    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int maxLeft = max(root->val, root->val + left);
        ans = max(ans, maxLeft);

        int right = dfs(root->right);
        int maxRight = max(root->val, root->val + right);
        ans = max(ans, max(maxRight, left + right + root->val));

        return max(maxLeft, maxRight);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
