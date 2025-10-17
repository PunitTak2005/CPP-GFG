class Solution {
  public:
    int sum = 0;  // To maintain running sum

    void transformTree(Node *root) {
        if (root == nullptr) return;

        // Traverse the right subtree first (greater values)
        transformTree(root->right);

        // Update current node
        int original = root->data;
        root->data = sum;
        sum += original;

        // Traverse the left subtree
        transformTree(root->left);
    }
};
