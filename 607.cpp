class Solution {
public:
    // Build parent map and locate target node
    Node* buildParentMap(Node* root, int target, unordered_map<Node*, Node*>& parent) {
        queue<Node*> q;
        q.push(root);
        parent[root] = nullptr;
        
        Node* targetNode = nullptr;
        
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->data == target) targetNode = curr;
            
            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    
    int burnTime(Node* targetNode, unordered_map<Node*, Node*>& parent) {
        unordered_map<Node*, bool> vis;
        queue<Node*> q;
        
        q.push(targetNode);
        vis[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            bool anyNew = false;
            
            for (int i = 0; i < sz; i++) {
                Node* curr = q.front();
                q.pop();
                
                if (curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                    anyNew = true;
                }
                if (curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                    anyNew = true;
                }
                if (parent[curr] && !vis[parent[curr]]) {
                    vis[parent[curr]] = true;
                    q.push(parent[curr]);
                    anyNew = true;
                }
            }
            if (anyNew) time++;
        }
        return time;
    }
    
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parent;
        Node* targetNode = buildParentMap(root, target, parent);
        return burnTime(targetNode, parent);
    }
};
