// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int temp[n+1]={0};
        int a,b;
        for(int i =0;i<n;i++)
         temp[arr[i]]++;
        for(int i=0;i<n+1;i++)
        {
            if(temp[i]==2)
             b=i;
            if(temp[i]==0)
             a=i;
        }
        int *as=new int[2];
       as[0]=b;
       as[1]=a;
       return as;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends