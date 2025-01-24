//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends


class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
         string str1="", str2="";

        while(num1!=nullptr){

            str1+=(num1->data+'0');

            num1=num1->next;

        }

        while(num2!=nullptr){

            str2+=(num2->data+'0');

            num2=num2->next;

        }

        string ans="";

        int carry=0;

        int i=str1.size()-1, j=str2.size()-1;

        while(i>=0||j>=0||carry){

            int sum=carry;

            if(i>=0) sum+=(str1[i--]-'0');

            if(j>=0) sum+=(str2[j--]-'0');

            carry=sum/10;

            ans+=(sum%10+'0');

        }

        Node* newHead=new Node(ans[0]-'0');

        Node* ptr=newHead;

        for(size_t k=1; k<ans.size(); k++){

            ptr->next=new Node(ans[k]-'0');

            ptr=ptr->next;

        }

        newHead=reverse(newHead);

        while(newHead->data==0){

            newHead=newHead->next;

        }

        return newHead;

    }

    Node* reverse(Node* head){

        if(head==nullptr|| head->next==nullptr){

            return head;

        }

        Node* newHead=reverse(head->next);

        Node* front=head->next;

        front->next=head;

        head->next=nullptr;

        return newHead;

    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends