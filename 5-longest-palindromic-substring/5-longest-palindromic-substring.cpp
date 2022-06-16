class Solution {
public:
    string longestPalindrome(string s) {

        int n=s.size();
        int maxLength=1, start=0;
        string ans;
        
        for(int i=0; i<n; i++)
        {
            int l=i-1;    //left pointer
            int r=i+1;   //right pointer
            
//If s[i]=s[l] then that means this substring is palindromic and we need to move l to the left to further check if it's palindromic or not
            while(l>=0 && s[i]==s[l])
            {
                l--;
            }
//If s[i]=s[r] then that means this substring is palindromic and we need to move r to the right to further check if it's palindromic or not
            while(r<n && s[i]==s[r])
            {
                r++;
            }
//If s[l]=s[r] then the substring b/w l & r is palindromic and we need to move l to the left and r to the right at the same time to check if its palindromic
            while(l>=0 && r<n && s[l]==s[r])
            {
                l--;
                r++;
            }
        //Substring starting from (l+1)th index and ending at (r-1)th index
            int length=(r-1)-(l+1)+1;  
            if(length>maxLength)
            {
                maxLength=length;
                start=l+1;  //Substring starts from (l+1)th index
            }
        }
        ans=s.substr(start,maxLength);
        return ans;
}
};