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
    bool ans = true;

public:
    bool isValidBST(TreeNode* root,
        int minVal = numeric_limits<int>::min(),
        int maxVal = numeric_limits<int>::max()
    ) {
        return root == nullptr ||
            (
                root->val < maxVal && root->val > minVal &&
                isValidBST(root->left, minVal, root->val) &&
                isValidBST(root->right, root->val, maxVal)
            );
    }
};
