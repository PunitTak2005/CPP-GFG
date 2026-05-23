class Solution {
public:
    // Helper: returns sum of subtree rooted at 'root'
    int dfs(Node* root) {
        if (!root) return 0;

        int oldVal = root->data;

        int leftSum  = dfs(root->left);
        int rightSum = dfs(root->right);

        // Update node's data to sum of left and right subtrees
        root->data = leftSum + rightSum;

        // Returns total sum of subtree rooted at 'root'
        return leftSum + rightSum + oldVal;
    }

    void toSumTree(Node* root) {
        dfs(root);
    }
};
