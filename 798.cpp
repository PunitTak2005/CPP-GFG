/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/

class Solution {
  public:
    int res;

    int maxToLeaf(Node* root) {
        if (!root) return INT_MIN;

        // Leaf node
        if (!root->left && !root->right) {
            return root->data;
        }

        int ls = maxToLeaf(root->left);
        int rs = maxToLeaf(root->right);

        // If both children exist, we can form a leaf-to-leaf path through this node
        if (root->left && root->right) {
            if (ls != INT_MIN && rs != INT_MIN) {
                res = max(res, ls + rs + root->data);
            }
            return max(ls, rs) + root->data;
        }

        // Only one child exists
        return (root->left ? ls : rs) + root->data;
    }

    int maxPathSum(Node *root) {
        res = INT_MIN;

        maxToLeaf(root);

        if (res == INT_MIN) {
            return -1;
        }

        return res;
    }   // <-- end of maxPathSum
};      // <-- end of class Solution
