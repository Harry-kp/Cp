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
    int maxDepth(Node* r) {
        if(!r)return 0;
        
        int d = 0;
        for(auto v:r->children)
        {
            int tmp = maxDepth(v);
            d = max(d,tmp);
        }
        return d+1;
    }
};