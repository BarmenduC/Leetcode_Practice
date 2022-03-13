class Solution {
public:
   bool isValid(string s) 
     {
        stack<char> st;
        int len=s.size();
        if(len%2) return false;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);          // if open bracket push on stack
            else
            {
                if(st.empty()) return false;
                char c=st.top();
                if((c=='(' && s[i]==')') || (c=='[' && s[i]==']') || (c=='{' && s[i]=='}')) st.pop();
                else return false;
            }
                
        }
        if(st.empty()) return true;
        else return false;
        
    }

};