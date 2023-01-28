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
        int update = -n;
        ListNode * temp = head,* ptr;
        while(temp->next!=NULL){
            update++;
            if(update>=0)ptr = temp;
            temp = temp->next;
        }
        
        *ptr = *ptr->next;
        return head;
    }
};