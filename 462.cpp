class Solution {
  public:
    // Helper recursive function
    Node* constructTreeUtil(vector<int> &pre, vector<int> &post, int &preIndex,
                            int l, int h, int size) {
        if (preIndex >= size || l > h)
            return nullptr;

        // Create root node from current preorder element
        Node* root = new Node(pre[preIndex++]);

        // If only one element, it's a leaf node
        if (l == h)
            return root;

        // Find the next preorder element in postorder
        int i;
        for (i = l; i <= h; ++i)
            if (pre[preIndex] == post[i])
                break;

        if (i <= h) {
            // Recursively construct left and right subtrees
            root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
            root->right = constructTreeUtil(pre, post, preIndex, i + 1, h - 1, size);
        }

        return root;
    }

    // Main function
    Node* constructTree(vector<int> &pre, vector<int> &post) {
        int preIndex = 0;
        int size = pre.size();
        return constructTreeUtil(pre, post, preIndex, 0, size - 1, size);
    }
};

