/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void traverse(Node* root, vector<int> &ans) {
        if (root == NULL) return;  // Base case

        // Visit left subtree
        traverse(root->left, ans);
        // Visit right subtree
        traverse(root->right, ans);
        // Visit node itself
        ans.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
