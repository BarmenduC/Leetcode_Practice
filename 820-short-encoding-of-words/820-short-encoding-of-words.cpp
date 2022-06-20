class Solution {
public:
struct TrieNode
{
    vector<TrieNode*>children ;
    bool isEnd;
    string word;
    TrieNode()
    {
    children = vector<TrieNode*>(26,nullptr);
            isEnd =0;
            word ="";
    }
};
    void insert(TrieNode* root , string s)
    {
        TrieNode* cur = root;
        for(auto x : s)
        {
            int idx = x-'a';
            if(cur->children[idx]==nullptr)
                cur->children[idx]= new TrieNode();
            cur = cur->children[idx];
        }
        if(!cur->isEnd){
        cur->isEnd =1;
        cur->word= s;
        }
    }
    bool isLeaf(TrieNode*root)
    {
        for(auto x : root->children)
            if(x!=nullptr)return 0;
        return 1;
    }
    void getAll(TrieNode* root , string &s)
    {
        if(root->isEnd &&isLeaf(root))
        {
            auto k = root->word;
            reverse(k.begin(),k.end());
            s+=k;
            s+='#';
        }
        for(int i =0;i<26;i++)
        {
            if(root->children[i])
                getAll(root->children[i], s);
        }
    }
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto x : words)
        {
            auto s = x;
            reverse(s.begin(),s.end());
            insert(root,s);
        }
        string ans ="";
        getAll(root,ans);
        cout << ans;
        return ans.size();
        
    }
};