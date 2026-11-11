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
        if(root == nullptr) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> bfs;
        bfs.push(root);

        while(!bfs.empty()) {
            vector<int> tmp;
            int level = bfs.size();
            while(level != 0) {
                TreeNode* curr = bfs.front();
                bfs.pop();
                level--;

                tmp.push_back(curr->val);
                if(curr->left != nullptr) bfs.push(curr->left);
                if(curr->right != nullptr) bfs.push(curr->right);
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
