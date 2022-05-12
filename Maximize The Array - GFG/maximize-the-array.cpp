// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
   vector<int> maximizeArray(int arr1[], int arr2[], int n) {
           set<int> st;
           vector<int> v,res;
           
           for(int i=0;i<n;i++){
               v.push_back(arr1[i]);
               v.push_back(arr2[i]);
           }
           
           sort(v.begin(), v.end());
           
           int k = n;
           
           for(int i = v.size()-1;i >= 0;i--)
               if(!st.count(v[i]) && k>0){
                   st.insert(v[i]);
                   k--;
               }
               
               
           set<int> check;
           
           for(int i=0;i<n;i++)
               if(st.count(arr2[i]) != 0 && check.count(arr2[i]) == 0){
                   res.push_back(arr2[i]);
                   check.insert(arr2[i]);
               }
                   
               
                   
           for(int i=0;i<n;i++)
               if(st.count(arr1[i]) != 0 && check.count(arr1[i]) == 0){
                   res.push_back(arr1[i]);
                   check.insert(arr1[i]);
               }
                   
           return res;
   }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends