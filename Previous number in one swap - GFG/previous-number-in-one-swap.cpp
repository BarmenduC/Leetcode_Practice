// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string previousNumber(string num){
        // code here 
         
          stack<int> st;
    int smaller;
    
    int i;
    for( i=num.size()-1; i>=0; i--)
    {
        if(st.empty()|| num[st.top()]>=num[i])
        st.push(i);
        else
        {
            smaller=st.top();
            st.pop();
            while(!st.empty())
            {
            
                    if(num[st.top()]>num[smaller] && num[st.top()]<num[i])
                    smaller=st.top();
                    st.pop();
                
            }
            break;
        }
        
    }
    
    if(st.size()==num.size())
    return "-1";
  
    char a=num[i];
    num[i]=num[smaller];
    num[smaller]=a;
    if(num[0]=='0')
    return "-1";
    return num;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.previousNumber(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends