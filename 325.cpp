class Solution {
  public:
    int maxDepth(Node* n)
    // finding the most distant leaf node from given node
    {
        if (!n)
            return 0;
        return 1 + max(maxDepth(n->left), maxDepth(n->right));
    }

    int traverse(Node* n, int target, int& ret) {
        if (!n)
            return 0;
        // base case

        if (n->data == target) {
            ret = max(ret, maxDepth(n->right));
            ret = max(ret, maxDepth(n->left));
            return 1;
        }
        // target found, hence returning distance from it

        int val = traverse(n->left, target, ret);
        if (val)
        // (val != 0) means target was found at distance = val
        {
            ret = max(ret, val + maxDepth(n->right));
            // finding max Depth on right as target was on left
            return val + 1;
        }

        val = traverse(n->right, target, ret);
        if (val)
        // (val != 0) means target was found at distance = val
        {
            ret = max(ret, val + maxDepth(n->left));
            // finding max Depth on left as target was on right
            return val + 1;
        }

        return 0;
    }

    int minTime(Node* root, int target) {
        int ret = 0;
        traverse(root, target, ret);
        return ret;
    }
};
