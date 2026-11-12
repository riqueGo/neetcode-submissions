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
    int ans = -1;
    int count = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr || count == k) return ans;

        kthSmallest(root->left, k);
        count++;
        if(count == k) {
            ans = root->val;
            return ans;
        }
        kthSmallest(root->right, k);
        return ans;
    }
};
