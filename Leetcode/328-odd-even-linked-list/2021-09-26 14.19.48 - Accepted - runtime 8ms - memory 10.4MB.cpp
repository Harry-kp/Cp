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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return head;
        ListNode * p1,*p2,*tmp;
        p1 = head;
        p2 = head->next;
        tmp = p2;
        
        while(p2 and p2->next){
            p1->next = p2->next;
            p2->next = p2->next->next;
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = tmp;
        return head;
    }
};