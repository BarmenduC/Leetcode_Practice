class Solution {
public:
    string removeKdigits(string num, int k) {
       string str = "";    
       for (char x : num) {
           while (str.length() && str.back() > x && k) {
               str.pop_back();  k--;                                             
           }
           
           if (str.length() || x != '0') {str.push_back(x);}  
       }
       
       while (str.length() && k--) { str.pop_back(); }          
       if(str.empty()){return "0";}
        return str;
    }
};
