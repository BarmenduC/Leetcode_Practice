class WordFilter {
public:
    struct node {
        int next[55];
        vector<int> id;
        
        node() {
            fill(begin(next), end(next), -1);
        }
    };

    vector<node> trie;
    
    int getVal(char u) {
        if ( u == '#' ) return 53;
        if (isupper(u)) return u - 'A';
        return ( u - 'a' ) + 26;
    }
    
    void addString ( string s, int id ) {
        int v = 0;
        for ( auto u : s ) {
            int c = getVal(u);
            
            if ( trie[v].next[c] == -1 ) {
                trie[v].next[c] = trie.size();
                trie.push_back(node());
            }
            
            v = trie[v].next[c];
            trie[v].id.push_back ( id );
        }
        
        trie[v].id.push_back ( id );
    }
    
    int searchString ( string s ) {
        int v = 0;
        for ( auto u : s ) {
            int c = getVal(u);
            if ( trie[v].next[c] == -1 ) {
                return -1;
            }
            
            v = trie[v].next[c];
        }
        
        return trie[v].id.back();
    }
    
    WordFilter(vector<string>& words) {
        trie.push_back (node());
        for ( int i = 0; i < words.size(); i++ ) {
            string tmp;
            addString( tmp + '#' + words[i], i );
            
            for ( int j = words[i].size()-1; j >= 0; j-- ) {
                tmp += words[i][j];
                addString( tmp + '#' + words[i], i );
            }
        }
    }
    
    int f(string prefix, string suffix) {
        reverse(suffix.begin(), suffix.end());
        return searchString ( suffix + '#' + prefix );
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */