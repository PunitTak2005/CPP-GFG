/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: Find the middle of the linked list using slow/fast pointers
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Now slow points to the start of the second half
        
        // Step 2: Reverse the second half of the linked list
        ListNode* prev = nullptr;
        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        // prev now points to the head of the reversed second half
        
        // Step 3: Traverse both halves and compute maximum twin sum
        int max_sum = 0;
        ListNode* left = head;
        ListNode* right = prev;
        while (right != nullptr) {
            max_sum = max(max_sum, left->val + right->val);
            left = left->next;
            right = right->next;
        }
        
        return max_sum;
    }
};
