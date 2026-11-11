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
    bool balanced = true;

    int dfs(TreeNode* root) {
        if(!balanced) return -1;
        if(root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);

        int dist = left > right ? left - right : right - left;
        balanced = balanced && dist < 2;

        return max(left, right) + 1;
    }

public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
    }
};
