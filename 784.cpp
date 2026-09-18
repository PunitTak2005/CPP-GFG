class Solution {
public:
    void inorder(Node* root, int &prev, int &ans) {
        if (root == nullptr) return;

        inorder(root->left, prev, ans);

        if (prev != -1) {
            ans = min(ans, root->data - prev);
        }
        prev = root->data;

        inorder(root->right, prev, ans);
    }

    int absDiff(Node *root) {
        int prev = -1;
        int ans = INT_MAX;

        inorder(root, prev, ans);

        return ans;
    }
};
