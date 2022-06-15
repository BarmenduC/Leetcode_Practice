// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    


int findSubString(string str){
       unordered_set<char> st;
       for(auto i: str){
           st.insert(i);
       }
       unordered_map<char, int> mp;
       int l = INT_MAX, start = 0;
       for(int i = 0; i < str.size(); i++){
          mp[str[i]]++;
          if(mp.size() < st.size())
          continue;
          
          while(mp[str[start]] > 1){
              mp[str[start]]--;
              start++;
          }
          l = min(l, i - start + 1);
       }
       return l;
   }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends