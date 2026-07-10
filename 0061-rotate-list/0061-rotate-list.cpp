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
        if(head == NULL || k == 0) return head;
        ListNode* temp = head;
        int n = 0;
        while(temp->next != NULL){
            temp = temp->next;
            n++;
        }
        n++;
        k = k%n;
        k = n-k-1;
        temp->next = head;
        temp = head;
        for(int i = 0; i<k; i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};