class UnionFind{
    int size;
    int _numOfSets;
    vector<int> _parent, rank;
public:
    UnionFind(int size):size(size){
        _parent.resize(size+1);
        rank.resize(size+1);
        for(int i=0;i<size;i++) _parent[i] = i;
        _numOfSets = size;
    }
    
    int parent(int n){
        if(n==_parent[n]) return n;
        return _parent[n] = parent(_parent[n]);
    }
    
    void connect(int a, int b){
        a = parent(a);
        b = parent(b);
        if(a==b) return;
        _numOfSets--;
        if(rank[a] < rank[b]) _parent[a] = b;
        else if(rank[a] > rank[b]) _parent[b] = a;
        else{
            _parent[a] = b;
            rank[b]++;
        }
    }
    
    bool isConnected(int a, int b){
        return parent(a) == parent(b);
    }
    
    int numOfSets(){
        return _numOfSets;
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size(); 
        auto uf = UnionFind(n); 
        for(auto &pair:pairs) uf.connect(pair[0],pair[1]); //Union
        unordered_map<int,vector<int>> mp; //parent -> children
        for(int i=0;i<n;i++){
            int p = uf.parent(i);
            mp[p].push_back(i);    
        }
        string result = s;
        for(auto &p:mp) {
            auto &indices = p.second;
            string chars;
            for(auto i:indices) chars.push_back(s[i]); //Fetch all chars of group
            sort(chars.begin(), chars.end()); //Sort chars
            for(int i=0;i<indices.size();i++) //put chars on respective indices
                result[indices[i]] = chars[i];
        }
        return result;
    }
};