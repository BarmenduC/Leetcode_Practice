/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dataRightLeft( TreeNode* root, int level, int & noteLevel ,vector<int> & rightView ){
        if( root==NULL){
            return;
        }
        if( level > noteLevel){
            rightView.push_back(root->val);
            noteLevel = level;
        }
        level++;
        dataRightLeft(root->right,level,noteLevel,rightView);
        dataRightLeft(root->left,level,noteLevel,rightView);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        int level = 0, noteLevel = -1;
        dataRightLeft(root,level,noteLevel,rightView);
        return rightView;
    }
};