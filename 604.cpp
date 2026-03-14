class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> happy;
        string cur;

        function<void()> dfs = [&]() {
            if (happy.size() >= k) return;            // early stop
            if ((int)cur.size() == n) {
                happy.push_back(cur);
                return;
            }
            for (char c = 'a'; c <= 'c'; ++c) {
                if (!cur.empty() && cur.back() == c) continue;
                cur.push_back(c);
                dfs();
                cur.pop_back();
            }
        };

        dfs();
        if ((int)happy.size() < k) return "";
        return happy[k - 1];
    }
};
