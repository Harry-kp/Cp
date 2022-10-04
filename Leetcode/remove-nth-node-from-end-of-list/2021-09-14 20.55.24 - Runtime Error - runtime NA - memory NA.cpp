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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * nth_ptr = head;
        ListNode * nrml_ptr = head;
        int cnt = 0;
        
        while(nrml_ptr!=NULL){
            cnt++;
            if(cnt > n)
                nth_ptr = nth_ptr->next;
            
            nrml_ptr = nrml_ptr->next;
        }
        
        if(nth_ptr == head)return NULL;
        *nth_ptr = *nth_ptr->next;
    return head;
    }
};