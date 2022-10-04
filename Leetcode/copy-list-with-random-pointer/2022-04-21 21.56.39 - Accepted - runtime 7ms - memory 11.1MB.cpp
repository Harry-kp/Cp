/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
while(temp){
            Node* node = new Node(temp->val);
            node->next = temp->next;
            temp->next = node;
            temp = node->next;
        }
        
        temp = head;
        while(temp){
            temp->next->random = (temp->random)?temp->random->next:NULL;
            temp = temp->next->next;
        }
        
        Node* ans = head->next;
        temp = head->next;
        while(head){
            head->next = temp->next;
            head = head->next;
            if(!head) break;
            temp->next = head->next;
            temp = temp->next;
        }
        return ans;
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return head;
        Node* temp = head;
        
        //Create interweave list           
        while(temp!=NULL){
            Node * newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next=newNode;
            temp = newNode->next;
        }
       
       
        //  Assign random pointers
        temp = head;
        while(temp!=NULL){
            if(temp->random == NULL)
                temp->next->random=NULL;
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        //Remove interweaved list
        Node * head2 = head->next;
        Node*next = head->next;
        temp = head;
        
        while(temp!=NULL){
            temp->next = next->next;
            temp=temp->next;
            if(!temp)break;
            next->next = temp->next;
            next = next->next;
            
        }
        return head2;
    }
};