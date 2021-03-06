// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
   public:
   int find(vector<vector<int>> &a,int i,int j)
   {
       int a1=0,b=0,c=0;
       if(i-1>=0)
       a1=a[i-1][j];
       if(j-1>=0)
       b=a[i][j-1];
       if(i-1>=0 && j-1>=0)
       c=a[i-1][j-1];
       
       return a[i][j]-a1-b+c;
   }
   vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
       vector<vector<int>> ans(N,vector<int>(M,0));
       
       for(int i=0;i<N;i++)
       {
           for(int j=0;j<M;j++)
           {
              ans[i][j]=find(after,i,j); 
           }
       }
       return ans;
   }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M; 
        vector<vector<int>> after(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>after[i][j];
            }
        } 
        Solution obj;
        vector<vector<int>> before=obj.computeBeforeMatrix(N,M,after); 
        for(int i=0;i<before.size();i++){
            for(int j=0;j<before[i].size();j++){
                cout<<before[i][j]<<' ';
            } 
            cout<<endl;
        }
    }
}  // } Driver Code Ends