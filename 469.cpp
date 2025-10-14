int k_ref;

struct Node* kthSmallestRecur(struct Node* root) {
    // base case
    if (root == NULL)
        return NULL;

    // search in left subtree
    struct Node* left = kthSmallestRecur(root->left);

    // if k'th smallest is found in left subtree, return it
    if (left != NULL)
        return left;

    // if current element is k'th smallest, return it
    k_ref--;
    if (k_ref == 0)
        return root;

    // else search in right subtree
    return kthSmallestRecur(root->right);
}

// Function to find k'th largest element in BST
int kthSmallest(struct Node* root, int k) {
    // maintain index to count number of struct nodes processed so far
    int count = 0;
    k_ref = k;
    struct Node* res = kthSmallestRecur(root);
    if (res == NULL)
        return -1;
    else
        return res->data;
}
