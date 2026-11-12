class Solution {
private:
    vector<int> preorder;
    vector<int> inorder;

    int binarySearch(int target, int left, int right) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == target) return i;
        }
        return -1;
    }

    TreeNode* buildIn(int& preorderIdx, int inorderLeft, int inorderRight) {
        if (inorderLeft > inorderRight) return nullptr;

        int rootValue = preorder[preorderIdx++];
        int idx = binarySearch(rootValue, inorderLeft, inorderRight);

        TreeNode* root = new TreeNode(rootValue);

        root->left = buildIn(preorderIdx, inorderLeft, idx - 1);
        root->right = buildIn(preorderIdx, idx + 1, inorderRight);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;

        int preorderIdx = 0;
        return buildIn(preorderIdx, 0, inorder.size() - 1);
    }
};