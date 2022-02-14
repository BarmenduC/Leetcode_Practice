// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int CHARS = 26;

// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string str1, string str2);

// Driver program to run the case
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str1,str2;
        cin>>str1>>str2;
        cout << remAnagram(str1, str2);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends


// function to calculate minimum numbers of characters
// to be removed to make two strings anagram
int remAnagram(string s1, string s2)
{
int i,a[26]={0},b[26]={0},res=0;
   for(i=0; i<s1.size(); i++){
       int x=s1[i]-'a';
       a[x]++;
   }
   for(i=0; i<s2.size(); i++){
       int x=s2[i]-'a';
       b[x]++;
   }
   for(i=0; i<26; i++){
       if(a[i] && b[i])res+=abs(a[i]-b[i]);
       else res+=a[i]+b[i];
   }
   
   return res;
}