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
    void dfs(TreeNode* root, int maxRoot, int& ans) {
        if(root == nullptr) return;
        if(root->val >= maxRoot) {
            maxRoot = root->val;
            ans++;
        }

        dfs(root->left, maxRoot, ans);
        dfs(root->right, maxRoot, ans);
    }

public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, -101, ans);
        return ans;
    }
};
