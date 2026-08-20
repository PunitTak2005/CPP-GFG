class Solution {
    int ans = INT_MIN;

    int dfs(Node* root) {
        if (!root) return INT_MAX;

        // Leaf cannot be an ancestor of any descendant
        if (!root->left && !root->right) return root->data;

        int leftMin = dfs(root->left);
        int rightMin = dfs(root->right);

        int minDescendant = min(leftMin, rightMin);

        // Current node is ancestor, minDescendant is below it
        ans = max(ans, root->data - minDescendant);

        // Return minimum value in this subtree
        return min(root->data, minDescendant);
    }

public:
    int maxDiff(Node* root) {
        dfs(root);
        return ans;
    }
};
