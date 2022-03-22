class Solution {
public:
    string getSmallestString(int n, int k) {
    if(k<n) return "";
    string s="";
    for(int i=0;i<n;i++)
        s+='a';
    int count=n;
    int remaining=k-count;
    int i=s.length()-1;
    while(remaining>0){
        if(remaining<=25){
            s[i]='a' + remaining;
            return s;
        }
        s[i]='a' + 25;
        remaining-=25;
        i--;
    }
    return s;
	
}
};