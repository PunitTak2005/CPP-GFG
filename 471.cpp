class Solution {
public:
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> arr;
        inorder(root, arr); // Sorted list from BST

        int n = arr.size();
        int pos = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

        int left = pos - 1;
        int right = pos;
        vector<int> result;

        while (k-- > 0) {
            if (left >= 0 && right < n) {
                int leftDiff = abs(arr[left] - target);
                int rightDiff = abs(arr[right] - target);
                if (leftDiff <= rightDiff) {
                    result.push_back(arr[left]);
                    left--;
                } else {
                    result.push_back(arr[right]);
                    right++;
                }
            } else if (left >= 0) {
                result.push_back(arr[left--]);
            } else if (right < n) {
                result.push_back(arr[right++]);
            }
        }
        return result; // driver code will sort before output
    }
};
