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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> bfs;
        bfs.push(root);

        vector<int> ans;
        TreeNode* curr;
        while(!bfs.empty()) {
            for(int level = bfs.size(); level != 0; level--) {
                curr = bfs.front();
                bfs.pop();

                if(curr->left != nullptr) bfs.push(curr->left);
                if(curr->right != nullptr) bfs.push(curr->right);
            }

            ans.push_back(curr->val);
        }

        return ans;
    }
};
