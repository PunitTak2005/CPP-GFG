class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men,
                               vector<vector<int>> &women) {
        int n = men.size();

        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; ++w) {
            for (int pos = 0; pos < n; ++pos) {
                int m = women[w][pos];
                rank[w][m] = pos;
            }
        }

        vector<int> womanPartner(n, -1);   // womanPartner[w] = man
        vector<int> nextProposal(n, 0);    // next woman index for each man

        queue<int> freeMen;
        for (int m = 0; m < n; ++m) freeMen.push(m);

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][nextProposal[m]++];  // next woman on m's list

            if (womanPartner[w] == -1) {
                // Woman w is free
                womanPartner[w] = m;
            } else {
                int current = womanPartner[w];
                // Check if w prefers m over current
                if (rank[w][m] < rank[w][current]) {
                    // w dumps current and gets engaged to m
                    womanPartner[w] = m;
                    freeMen.push(current);
                } else {
                    // w stays with current; m remains free
                    freeMen.push(m);
                }
            }
        }

        // Build result from men's perspective
        vector<int> result(n);
        for (int w = 0; w < n; ++w) {
            int m = womanPartner[w];
            result[m] = w;
        }
        return result;
    }
};class Solution {
public:
    vector<int> stableMarriage(vector<vector<int>> &men,
                               vector<vector<int>> &women) {
        int n = men.size();

        // rank[w][m] = preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));
        for (int w = 0; w < n; ++w) {
            for (int pos = 0; pos < n; ++pos) {
                int m = women[w][pos];
                rank[w][m] = pos;
            }
        }

        vector<int> womanPartner(n, -1);   // womanPartner[w] = man
        vector<int> nextProposal(n, 0);    // next woman index for each man

        queue<int> freeMen;
        for (int m = 0; m < n; ++m) freeMen.push(m);

        while (!freeMen.empty()) {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][nextProposal[m]++];  // next woman on m's list

            if (womanPartner[w] == -1) {
                // Woman w is free
                womanPartner[w] = m;
            } else {
                int current = womanPartner[w];
                // Check if w prefers m over current
                if (rank[w][m] < rank[w][current]) {
                    // w dumps current and gets engaged to m
                    womanPartner[w] = m;
                    freeMen.push(current);
                } else {
                    // w stays with current; m remains free
                    freeMen.push(m);
                }
            }
        }

        // Build result from men's perspective
        vector<int> result(n);
        for (int w = 0; w < n; ++w) {
            int m = womanPartner[w];
            result[m] = w;
        }
        return result;
    }
};
