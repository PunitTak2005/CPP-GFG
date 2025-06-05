class Solution {
  public:
    vector<int> search(string &pat, string &txt) {

        // Number of characters in the input alphabet (ASCII)
        int d = 256;

        // A prime number for modulo operations to reduce collisions
        int q = 101;

        // Length of the pattern
        int m = pat.length();

        // Length of the text
        int n = txt.length();

        // Hash value for pattern
        int ph = 0;

        // Hash value for current window of text
        int th = 0;

        // High-order digit multiplier
        int h = 1;

        vector<int> res;

        // Precompute h = pow(d, m-1) % q
        for (int i = 0; i < m - 1; i++)
            h = (h * d) % q;

        // Compute initial hash values for pattern and first window of text
        for (int i = 0; i < m; i++) {
            ph = (d * ph + pat[i]) % q;
            th = (d * th + txt[i]) % q;
        }

        // Slide the pattern over text one by one
        for (int i = 0; i <= n - m; i++) {

            // If hash values match, check characters one by one
            if (ph == th) {
                bool ok = true;
                for (int j = 0; j < m; j++) {
                    if (txt[i + j] != pat[j]) {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    res.push_back(i + 1);
            }

            // Calculate hash value for the next window
            if (i < n - m) {
                th = (d * (th - txt[i] * h) + txt[i + m]) % q;

                // Ensure hash value is non-negative
                if (th < 0)
                    th += q;
            }
        }

        return res;
    }
};
