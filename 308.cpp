//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/


// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    vector<bool> sieve(int maxVal) {
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= maxVal; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i)
                    isPrime[j] = false;
            }
        }
        return isPrime;
    }

    // Find nearest prime to given number x
    int nearestPrime(int x, const vector<bool>& isPrime) {
        if (isPrime[x]) return x;
        int offset = 1;
        while (true) {
            if (x - offset >= 2 && isPrime[x - offset]) return x - offset;
            if (x + offset < isPrime.size() && isPrime[x + offset]) return x + offset;
            offset++;
        }
    }

    Node* primeList(Node* head) {
        const int MAX = 20000;
        vector<bool> isPrime = sieve(MAX);
        
        Node* curr = head;
        while (curr != nullptr) {
            curr->val = nearestPrime(curr->val, isPrime);
            curr = curr->next;
        }

        return head;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
