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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // First, check if there are at least k nodes left in the linked list
        ListNode* current = head;
        for (int i = 0; i < k; ++i) {
            if (!current) return head; // If there are less than k nodes, return head
            current = current->next;
        }
        
        // Now we have at least k nodes, we can reverse them
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        current = head;
        for (int i = 0; i < k; ++i) {
            next = current->next; // Store next node
            current->next = prev; // Reverse the link
            prev = current;       // Move prev to current
            current = next;       // Move current to next
        }
        
        // Recursively call for the next groups
        if (next) {
            head->next = reverseKGroup(next, k);
        }
        
        // Return the new head of the reversed group
        return prev;
    }
};

