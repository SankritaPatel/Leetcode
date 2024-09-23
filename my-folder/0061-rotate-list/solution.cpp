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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        int l = length(head);
        k = k%l;
        if(k==0) return head;
        ListNode* tail = head;
        for(int i=1;i<l;i++){
            tail = tail->next;
        }
        ListNode* newTail = head;
        for(int i=1;i<l-k;i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        tail->next = head;
        return newHead;

    }

private:
    int length(ListNode* head) {
        int l = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            l++;
            temp = temp->next;
        }
        return l;
    }
};
