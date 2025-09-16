#include <bits/stdc++.h>
using namespace std;

// Function to compute GCD
long long gcd(long long a, long long b) {
    while (b) {
        long long t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute LCM
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

vector<int> replaceNonCoprimes(vector<int>& nums) {
    vector<long long> st;  // Use long long to avoid overflow
    for (int num : nums) {
        long long x = num;
        while (!st.empty() && gcd(st.back(), x) > 1) {
            x = lcm(st.back(), x);
            st.pop_back();
        }
        st.push_back(x);
    }
    
    // Convert back to int
    vector<int> res;
    for (long long x : st) res.push_back((int)x);
    return res;
}

int main() {
    vector<int> nums = {6,4,3,2,7,6,2};
    vector<int> ans = replaceNonCoprimes(nums);
    for (int x : ans) cout << x << " ";
    cout << endl;
    return 0;
}
