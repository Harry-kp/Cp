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
    bool hasCycle(ListNode *head) {
        int cnt = 100000;
        
        while(head!=NULL){
            cnt--;
            if(cnt<0)return true;
            head = head->next;
        }
        return false;
    }
};