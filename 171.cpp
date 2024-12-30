
#include <bits/stdc++.h>
using namespace std;






class Solution {
public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        set<int> setA(a.begin(), a.end());
        set<int> setB(b.begin(), b.end());
        set<int> commonElements;

        for (int element : setA) {
            if (setB.find(element) != setB.end()) {
                commonElements.insert(element);
            }
        }

        vector<int> result(commonElements.begin(), commonElements.end());
        return result;
    }
};




int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

