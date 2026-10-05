/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> v;
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(v.count(node)) return v[node];
        Node* nd=new Node(node->val);
        v[node]= nd;
        for(auto & n:node->neighbors){
            nd->neighbors.push_back(cloneGraph(n));
        }
        return nd;
    }
};