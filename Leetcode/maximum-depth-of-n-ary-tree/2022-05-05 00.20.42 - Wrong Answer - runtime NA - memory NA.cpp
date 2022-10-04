/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root)return 0;
        stack<Node*> s;
        s.push(root);
        int ans = 0;
        
        while(!s.empty()){
            ans = (ans<s.size())?s.size():ans;
            Node * v = s.top();
            s.pop();
            for(auto x:v->children)
                if(v)
                    s.push(x);
        }
        return ans;
    }
};