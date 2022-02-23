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
    unordered_map<int, Node*> m;
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        Node* head = new Node();
        head->val = node->val;
        m[node->val] = head;
        for(auto n: node->neighbors){
            if(m.find(n->val)==m.end()){
                m[n->val] = cloneGraph(n);
            }
            head->neighbors.push_back(m[n->val]);
        }
        return head;
    }
};