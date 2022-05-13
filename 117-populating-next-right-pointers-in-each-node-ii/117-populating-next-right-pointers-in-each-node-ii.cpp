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

queue<Node*>temp;
Node* max;
Node* ptr;
Node* connect(Node* root) {
    if(!root)return root;
    temp.push(root);
    max = root;
    while(temp.size()){
        ptr = temp.front();
        //cout <<ptr->val;
        if(ptr->left)temp.push(ptr->left);
        if(ptr->right)temp.push(ptr->right);
        if(max==ptr){
            max = temp.back();
            temp.pop();
            ptr->next=NULL;
        }else{
            temp.pop();
            ptr->next = temp.front();
        }
    }
    return root;
}
};