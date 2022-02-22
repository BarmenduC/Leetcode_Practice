class Solution {
public:
   
      int titleToNumber(string columnTitle) {
  int  n=columnTitle.size();
    int ans=0;
	
    for(int i=0;i<n-1;i++){
        char c=columnTitle[i];
        int d=c-'A'+1;
        ans=(ans+d)*26;
      }
	  
  char  x=columnTitle[n-1];
    int ld=x-'A'+1;
    return ans+ld;
}
};