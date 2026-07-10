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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        ListNode* del;
        int carry = 0, sum = 0;
        while(temp1 != NULL && temp2 != NULL){
            sum = temp1->val + temp2->val + carry;
            // ListNode* node = new ListNode(sum%10);
            temp->val = sum%10;
            del = temp;
            temp->next = temp1;
            temp = temp->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
            carry = sum/10;
        }
        while(temp1 != NULL){
            sum = temp1->val + carry;
            // ListNode* node = new ListNode(sum%10);
            temp->val = sum%10;
            del = temp;
            temp->next = temp1;
            temp = temp->next;
            carry = sum/10;
            temp1 = temp1->next;
        }
        while(temp2 != NULL){
            sum = temp2->val + carry;
            // ListNode* node = new ListNode(sum%10);
            del = temp;
            temp->val = sum%10;
            temp->next = temp2;
            temp = temp->next;
            carry = sum/10;
            temp2 = temp2->next;
        }
        if(carry != 0){
            // ListNode* node = new ListNode(carry);
            temp->val = carry;
            temp->next = NULL;

        }
        else{
            del->next = NULL;
            delete temp;
        }
        // temp = ans;
        // ans = ans->next;
        // delete temp;
        return ans;
    }
};