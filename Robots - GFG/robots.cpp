// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


     class Solution{   
public:
   string moveRobots(string s1, string s2){
       int i=0,c1=0,c2=0,c3=0,c4=0,j=s2.length()-1;
       vector <pair<int,int>> B1,B2,A1,A2;
       
       while(i<s1.size())
       {
           if(s1[i]=='B')
           {
               B1.push_back({i,c1});
           }
           else if(s1[i]=='A')
           {
               c1++;
           }
           
           if(s2[i]=='B')
           {
               B2.push_back({i,c2});
           }
           else if(s2[i]=='A')
           {
               c2++;
           }
           i++;
           
           
           if(s1[j]=='A')
           {
               A1.push_back({j,c3});
           }
           else if(s1[j]=='B')
           {
               c3++;
           }
           
           if(s2[j]=='A')
           {
               A2.push_back({j,c4});
           }
           else if(s2[j]=='B')
           {
               c4++;
           }
           j--;
       }
       
       for(int j=0;j<B1.size();j++)
       {
           if(B1[j].first>B2[j].first || B1[j].second!=B2[j].second)
           return "No";
       }
       
       for(int j=0;j<A1.size();j++)
       {
           if(A1[j].first<A2[j].first || A1[j].second!=A2[j].second)
           return "No";
       }
       
       return "Yes";
   }
};
// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends