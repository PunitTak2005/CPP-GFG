class Solution {
  public:
    int res; // global maximum
    
    int maxPath(Node* root) {
        if (!root) return 0;
        
        // find max path sum from left and right subtrees
        int left = max(0, maxPath(root->left));   // ignore negative sums
        int right = max(0, maxPath(root->right));
        
        // update the global max if the current path is better
        res = max(res, root->data + left + right);
        
        // return the max gain for parent path
        return root->data + max(left, right);
    }
    
    int findMaxSum(Node *root) {
        res = INT_MIN;
        maxPath(root);
        return res;
    }
};
