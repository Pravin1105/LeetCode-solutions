/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp = headA;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = headB;
        ListNode* slow = headA;
        ListNode* fast = headA;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                fast = headA;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                temp->next = NULL;
                return fast;
            }
        }
        temp->next = NULL;
        return NULL;
    }
};