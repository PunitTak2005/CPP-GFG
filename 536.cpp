class Solution {
  public:
    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        // Step 1: Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        // Step 2: Add digits
        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }

        // Step 3: Reverse result
        Node* result = reverse(dummy->next);

        // Step 4: Remove leading zeros
        while (result && result->data == 0 && result->next) {
            result = result->next;
        }

        return result;
    }
};
