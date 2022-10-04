/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node *curr = root, *temp_node = new Node(0, NULL, NULL, NULL);
        while (curr) {
            for (Node* pre = temp_node; curr; curr = curr -> next) {
                if (curr -> left) {
                    pre -> next = curr -> left;
                    pre = pre -> next;
                }
                if (curr -> right) {
                    pre -> next = curr -> right;
                    pre = pre -> next;
                }
            }
            curr = temp_node -> next;
            temp_node -> next = NULL;
        }
        delete temp_node;
        return root;
    }
};