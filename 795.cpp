class Solution {
public:
    string lexiString(string &s) {
        int n = s.size();
        string doubled = s + s;

        int i = 0, j = 1, k = 0;

        while (i < n && j < n && k < n) {
            char a = doubled[i + k];
            char b = doubled[j + k];

            if (a == b) {
                k++;
            } 
            else if (a > b) {
                i = i + k + 1;
                if (i <= j) i = j + 1;
                k = 0;
            } 
            else {
                j = j + k + 1;
                if (j <= i) j = i + 1;
                k = 0;
            }
        }

        int start = min(i, j);
        return doubled.substr(start, n);
    }
};
