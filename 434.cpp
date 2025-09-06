class Solution {
  public:
    // Returns count of nodes present in loop.
    int countNodes(Node* node) {
        int res = 1;
        Node* curr = node;
        while (curr->next != node) {
            res++;
            curr = curr->next;
        }
        return res;
    }

    int lengthOfLoop(Node* head) {
        Node *slow = head, *fast = head;

        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;

            // If slow and fast meet at
            // some point then there is a loop
            if (slow == fast)
                return countNodes(slow);
        }

        // Return 0 to indicate that
        // there is no loop
        return 0;
    }
};
