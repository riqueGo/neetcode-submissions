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
    TreeNode* ans = nullptr;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(ans != nullptr) return ans;

        if(root->val == p->val
            || root->val == q->val
            || (p->val > root->val && q->val < root->val)
            || (p->val < root->val && q->val > root->val)
        ) {
            ans = root;
        } else if(p->val > root->val && q->val > root->val) {
            lowestCommonAncestor(root->right, p, q);
        } else {
            lowestCommonAncestor(root->left, p, q);
        }

        return ans;
    }
};
