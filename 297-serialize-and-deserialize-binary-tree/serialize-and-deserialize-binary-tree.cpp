/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* root, string &s) {
        if (root == NULL) {
            s += "N,";
            return;
        }
        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }
        TreeNode* buildTree(string &data, int &index) {
        if (index >= data.size())
            return NULL;
        if (data[index] == 'N') {
            index += 2;         
            return NULL;
        }
        string value = "";

        while (data[index] != ',') {
            value += data[index];
            index++;
        }
        index++;
        TreeNode* root = new TreeNode(stoi(value));
        root->left = buildTree(data, index);
        root->right = buildTree(data, index);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return buildTree(data, index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));