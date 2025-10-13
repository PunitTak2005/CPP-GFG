class Solution {
  public:
    vector<int> maxSumHelper(Node* root) {
        if (root == NULL)
            return {0, 0};

        vector<int> resLeft = maxSumHelper(root->left);
        vector<int> resRight = maxSumHelper(root->right);

        int include = root->data + resLeft[1] + resRight[1];
        int exclude = max(resLeft[0], resLeft[1]) + max(resRight[0], resRight[1]);

        // returns a vector having 2 values
        // 1st value being max sum when root node is included
        // 2nd value being max sum when root node is excluded
        return {include, exclude};
    }

    int getMaxSum(Node* root) {
        vector<int> res = maxSumHelper(root);

        return max(res[0], res[1]);
    }
};
