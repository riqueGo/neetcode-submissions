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

class Codec {
private:
    TreeNode* deserializeNode(int& cursor, const string& data) {
        if(data[cursor] == 'n')  {
            cursor++;
            return nullptr;
        }

        int offset = cursor;
        while(data[offset] != '#') offset++;
        int len = stoi(data.substr(cursor, offset-cursor));

        offset++;
        cursor = offset+len;
        return new TreeNode(stoi(data.substr(offset, len)));
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        stringstream ss;

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if(curr == nullptr) {
                ss << "n";
                continue;
            }

            string valStr = to_string(curr->val);
            ss << valStr.length() << "#" << valStr;
            
            q.push(curr->left);
            q.push(curr->right);
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int cursor = 0;
        queue<TreeNode*> q;
        TreeNode* root = deserializeNode(cursor, data);
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front(); q.pop();

            if(curr == nullptr) continue;

            curr->left = deserializeNode(cursor, data);
            curr->right = deserializeNode(cursor, data);

            q.push(curr->left);
            q.push(curr->right);
        }

        return root;
    }
};
