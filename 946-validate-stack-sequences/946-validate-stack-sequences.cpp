class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        //test feature of stack
        //ask same size
        //ask sorted array?
        //ask duplicate?
        //left index vs right index
        //key order will be the same, (no invert)
        int n = pushed.size();
        vector<int> left(1000,0);
        //stored
        for(int i = 0; i<n; i++){
            left[pushed[i]] = i;
        }
        int last = left[popped[0]];
        int m = INT_MAX;
        int M = INT_MIN;
        //s.insert(1,2,3,4)
        //stack<int>
        /*
        for(int i = 0; i<n; i++){
            if(m!= INT_MAX && left[popped[i]]< m-1 
               || M!=INT_MIN && left[popped[i]] > M+1){
                return false;
            }
            m = min(left[popped[i]],m);
            M = max(left[popped[i]],M);
        }*/
        //[left, right]
        //4,5
        //find left index
        //[1,2,3,4,5]
        // 0 1 2 3 4
        
        //[4,3,5,1,2]
        // 3 2 4 0 1?
        //>1
        
        stack<int> s;
        int r = 0;
        for(int i = 0; i<n; i++){
           s.push(i);
           while(!s.empty() && pushed[s.top()] == popped[r]){
               s.pop();
               r++;
           }
        }
        return s.empty();   
    }
};