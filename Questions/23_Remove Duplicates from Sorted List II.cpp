// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/

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
    ListNode* deleteDuplicates(ListNode* head) {
        // Create a dummy node to simplify handling of the edge case (empty list).
        ListNode* temp = new ListNode(0);

        // Connect the dummy node to the head of the linked list.
        temp->next = head;
        ListNode* pre = temp; // Pointer to the node before the current node.
        ListNode* curr = head; // Pointer to the current node.

        while(curr != NULL) {
            // Iterate through consecutive duplicate nodes.
            while(curr->next != NULL && pre->next->val == curr->next->val) {
                curr = curr->next;
            } 

            // Check if no duplicates were found.
            if(pre->next == curr) {
                pre = pre->next; // Move the pre pointer to the next distinct node.
            } else {
                // Skip the duplicates by updating the next pointer of the pre node.
                pre->next = curr->next;
            }
            // Move to the next node in the linked list.
            curr = curr->next;
        }

        // Return the modified linked list starting from the dummy node's next.
        return temp->next;
    }
};
