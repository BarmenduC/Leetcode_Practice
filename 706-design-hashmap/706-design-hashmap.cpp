class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        size = 0;
        bucket_size = 16; // no need to use prime number because the size grow up
        threshold = 0.8; // litterature show 0.8 is the best performance space
        buckets = new list<pair<int,int>>[bucket_size];
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        p = find(key);
        if(p.first){
            (*(p.second)).second = value;
        }else{
            int index = key & (bucket_size-1); // modulo operation because bucket is power of 2
            buckets[index].push_back(make_pair(key,value));
            ++size;
            load_factor = (double) size / bucket_size;
            if(load_factor > threshold){
                resize();
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        p = find(key);
        if(p.first){
            return (*(p.second)).second;
        }
        return -1;
    }
    
    pair<bool,list<pair<int,int>>::iterator> find(int key){
        index = key & (bucket_size-1);
        for(list<pair<int,int>>::iterator itr = buckets[index].begin() ; itr != buckets[index].end() ; ++itr){
            if((*itr).first == key){
                return make_pair(true,itr);
            }
        }
        return make_pair(false,list<pair<int,int>>::iterator{});
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        p = find(key);
        if(p.first){
            index = key & (bucket_size-1);
            buckets[index].erase(p.second);
            --size;
        }        
    }
    
    void resize(){
        unsigned new_bucket_size = bucket_size * 2;
        list<pair<int,int>> * new_buckets = new list<pair<int,int>>[new_bucket_size];
        
        for(int i = 0 ; i < bucket_size ; ++i){            
            for (pair<int,int> key_value : buckets[i]){
                index = key_value.first & (new_bucket_size-1);
                new_buckets[index].push_back(key_value);                
            }
        }        
        delete[] buckets;
        buckets = new_buckets;
        bucket_size = new_bucket_size;
        
    }
private:
    unsigned bucket_size ;
    double load_factor;
    double threshold ;
    list<pair<int,int>> *buckets;
    unsigned size ;
    pair<bool,list<pair<int,int>>::iterator>  p;
    unsigned index ;
};