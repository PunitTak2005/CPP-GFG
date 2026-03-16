class Solution
{
public:
    int countAllPaths(Node *root, int k)
    {
        unordered_map<long long, int> mp;
        mp[0] = 1; // empty prefix
        
        long long ans = 0;
        function<void(Node*, long long)> dfs = [&](Node* node, long long currSum) {
            if (!node) return;
            
            currSum += node->data;
            
            long long need = currSum - k;
            if (mp.count(need)) ans += mp[need];
            
            mp[currSum]++;
            
            dfs(node->left, currSum);
            dfs(node->right, currSum);
            
            mp[currSum]--; // backtrack
        };
        
        dfs(root, 0);
        return (int)ans;
    }
};
