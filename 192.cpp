//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends


class Solution {
  public:
    void print(vector<int>&a)
    {
        for(int x : a)
        cout<<x<<" ";
        cout<<endl;
    }
    Node* rotate(Node* head, int k) {
        vector<int> ans;
        Node *curr = head;
        while(curr != NULL)
        {
            ans.push_back(curr->data);
            curr = curr->next;
        }
        int n = ans.size();
        k = k % n;
        reverse(ans.begin() ,ans.begin() + k);
        reverse(ans.begin() + k , ans.end());
        reverse(ans.begin() , ans.end());
        curr = head;
        for(int &x : ans)
        {
            curr->data = x;
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

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends
