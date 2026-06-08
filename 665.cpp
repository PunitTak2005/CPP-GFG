/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    // Helper to reverse a singly linked list in-place
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;  // new head
    }

    Node *compute(Node *head) {
        if (!head || !head->next) return head;

        // Step 1: reverse the list
        head = reverse(head);

        // Step 2: traverse reversed list and delete smaller nodes
        int max_so_far = head->data;
        Node* curr = head->next;
        Node* prev = head;

        while (curr != nullptr) {
            if (curr->data >= max_so_far) {
                max_so_far = curr->data;
                prev = curr;
                curr = curr->next;
            } else {
                // delete curr by skipping it
                prev->next = curr->next;
                curr = prev->next;
            }
        }

        // Step 3: reverse again to restore original order
        head = reverse(head);
        return head;
    }
};
