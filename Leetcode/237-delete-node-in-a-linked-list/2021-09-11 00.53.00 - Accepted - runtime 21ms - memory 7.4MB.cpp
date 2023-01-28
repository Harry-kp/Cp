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
    void deleteNode(ListNode* node) {
        ListNode* prev;
        while(node->next!=NULL){
            swap(node->next->val,node->val);
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
        // free(node);
        
    }
};