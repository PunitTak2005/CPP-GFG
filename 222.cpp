/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
      
    // Function to merge K sorted linked lists.
   
        priority_queue<int, vector<int>, greater<int>> pq;

        // Insert all elements from the K lists into the priority queue.
        for (auto list : arr) {
            Node* node = list;
            while (node) {
                pq.push(node->data);
                node = node->next;
            }
        }

        // Dummy head for the merged list.
        Node* head = new Node(-1);
        Node* tail = head;

        // Construct the merged linked list.
        while (!pq.empty()) {
            tail->next = new Node(pq.top());
            pq.pop();
            tail = tail->next;
        }

        return head->next;
    }
};
