class Solution {
public:
    struct Node {
        int freq;
        int idx;          // smallest original index in this subtree
        Node *left, *right;
        // leaf
        Node(int f, int i) : freq(f), idx(i), left(NULL), right(NULL) {}
        // internal
        Node(Node* l, Node* r) {
            freq = l->freq + r->freq;
            idx = min(l->idx, r->idx); // important for tie-breaking
            left = l;
            right = r;
        }
    };

    struct Cmp {
        bool operator()(Node* a, Node* b) const {
            if (a->freq != b->freq)
                return a->freq > b->freq;   // smaller freq first
            return a->idx > b->idx;         // for same freq, smaller index first
        }
    };

    void preOrder(Node* root, string cur, vector<string> &ans) {
        if (!root) return;
        // leaf node -> one code
        if (!root->left && !root->right) {
            if (cur == "") cur = "0";      // single-character case
            ans.push_back(cur);
            return;
        }
        preOrder(root->left, cur + '0', ans);
        preOrder(root->right, cur + '1', ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = s.size();
        priority_queue<Node*, vector<Node*>, Cmp> pq;

        for (int i = 0; i < n; ++i) {
            pq.push(new Node(f[i], i));
        }

        // only one distinct character
        if (n == 1) return {"0"};

        // build Huffman tree
        while (pq.size() > 1) {
            Node* l = pq.top(); pq.pop();
            Node* r = pq.top(); pq.pop();
            pq.push(new Node(l, r));
        }

        Node* root = pq.top();
        vector<string> ans;
        preOrder(root, "", ans);
        return ans;
    }
};
