class Solution {
  public:
    // function to find the number of
    // moves to distribute all of the candies
    int distCandyUtil(Node* root, int& ans) {

        // Base Case
        if (root == nullptr)
            return 0;

        // Traverse left subtree
        int l = distCandyUtil(root->left, ans);

        // Traverse right subtree
        int r = distCandyUtil(root->right, ans);

        // Update number of moves
        ans += abs(l) + abs(r);

        // Return number of moves to balance
        // current node
        return root->data + l + r - 1;
    }

    int distCandy(Node* root) {
        int ans = 0;
        distCandyUtil(root, ans);
        return ans;
    }
};
