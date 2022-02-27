// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
 public:
   int mostBalloons(int N, pair<int, int> arr[]) {
     double s;
     int mx=0,k=0,ans=0;
     
     for(int i=0;i<N;i++)
     {
         unordered_map <double,int> umap;
         k=0;
         mx=0;
         for(int j=0;j<N;j++)
         {

            //there might be a possibility that two ballons are there in a single point.So,we keep track of those balloons as well
             if(arr[i]==arr[j])
             {
              k++;
              continue;
             }
             else if(arr[i].first-arr[j].first==0)
             s=INT_MAX*10000;
             else
   s=((double)(arr[i].second-arr[j].second))/((double)(arr[i].first-arr[j].first));
             umap[s]++;
             mx=max(mx,umap[s]);
         }
         ans=max(ans,mx+k);
     }
     return ans;
   }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        pair<int, int> arr[N];
        for (int i = 0; i < N; i++) {
            cin >> arr[i].first;
        }
        for (int i = 0; i < N; i++) {
            cin >> arr[i].second;
        }
        Solution ob;
        cout << ob.mostBalloons(N, arr) << endl;
    }
}  // } Driver Code Ends