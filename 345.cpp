/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        
        // Step 1: Detect loop using Floyd's algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Loop detected
            if (slow == fast) {
                return countLoopLength(slow);
            }
        }

        // No loop
        return 0;
    }

  private:
    // Helper function to count number of nodes in loop
    int countLoopLength(Node* loop_node) {
        int count = 1;
        Node* temp = loop_node->next;
        while (temp != loop_node) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
