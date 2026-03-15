class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        
        // column -> list of node values
        map<int, vector<int>> mp;
        // queue for BFS: node and its column index
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, col] = q.front();
            q.pop();
            
            mp[col].push_back(node->data);
            
            if (node->left) {
                q.push({node->left, col - 1});
            }
            if (node->right) {
                q.push({node->right, col + 1});
            }
        }
        
        // collect columns from leftmost to rightmost
        for (auto &p : mp) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
