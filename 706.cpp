class Solution {
  public:
    // Recursive function to calculate the length of the longest consecutive sequence in
    // the binary tree
    void longestConsecutiveUtil(Node* root, int curLength, int expected, int& res) {
        // Base case: if the current node is NULL, return
        if (root == NULL)
            return;

        // If the value of the current node is the expected value in the consecutive
        // sequence, increment the current length, otherwise reset the current length to
        // 1
        if (root->data == expected)
            curLength++;
        else
            curLength = 1;

        // Update the result with the maximum of the current length and the previous
        // result
        res = max(res, curLength);

        // Recursively call the function for the left and right subtrees,
        // updating the expected value to be the value of the current node plus 1
        longestConsecutiveUtil(root->left, curLength, root->data + 1, res);
        longestConsecutiveUtil(root->right, curLength, root->data + 1, res);
    }

    // Function to calculate the length of the longest consecutive sequence in the
    // binary tree
    int longestConsecutive(Node* root) {
        // Base case: if the root is NULL, the longest consecutive sequence length is 0
        if (root == NULL)
            return -1;

        int res = 0; // Initialize the result variable as 0

        // Call the recursive helper function to calculate the length of the longest
        // consecutive sequence
        longestConsecutiveUtil(root, 0, root->data, res);

        // If the result is less than or equal to 1, it means there is no consecutive
        // sequence, so return -1
        if (res <= 1)
            return -1;

        // Return the length of the longest consecutive sequence
        return res;
    }
};
