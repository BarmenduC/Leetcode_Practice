class Solution {
public:
    struct node {
        int r, c;
    };
    
    int row[9], col[9]; // to save rows and cols of queens
    vector<node> list; // to save queen locations
    vector<vector<string>> ans; // answer list
    vector<string> each_case; // one of answer list
    
    // to check current location is available or not
    bool is_available(int r, int c){
        if(row[r] == 1 || col[c] == 1) return false;
        for (node comp : list) {
            if(comp.c == c - comp.r + r || comp.c == c + comp.r - r) return false;
        }
        return true;
    }
    
    // make each available case and add to ans
    void make_ans(int r, int n) {
        // if compleated, then add it
        if(r == n) {
            ans.push_back(each_case);
            return;
        }
        // initial row status
        string cur ="";
        for (int i=0; i<n; i++) cur += '.';
        
        // check each column is available
        for (int c=0; c<n; c++) {            
            if(!is_available(r, c)) continue;
            
            // record status and go next row
            cur[c]='Q'; // put the queen at the current location
            row[r] = 1; col[c] = 1;  // record current row and col number
            list.push_back({r, c}); // save current location
            each_case.push_back(cur); // put the current row status
            make_ans(r+1, n); // go next row
            
            // recover to previous status
            each_case.pop_back();
            list.pop_back();
            row[r] = 0; col[c] = 0;
            cur[c]='.';
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        make_ans(0, n); // start at row 0
        return ans;
    }
};