class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // Base cases
        if (root == NULL)
            return -1;
        if (root->data == k)
            return k;

        // If root's value is smaller,
        // try in right subtree
        else if (root->data < k) {

            int x = findMaxFork(root->right, k);
            if (x == -1)
                return root->data;
            else
                return x;
        }

        // If root's key is greater,
        // return value from left subtree.
        return findMaxFork(root->left, k);
    }
};
