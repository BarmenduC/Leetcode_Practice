class Solution {
public:
    int findDuplicate(vector<int>& num) {
    
    int  l  = num.size();
    
    for(int i = 0;i<l;i++)
    {
       int index = abs(num[i])-1;
        
        num[index] = num[index]*(-1);
        if(num[index]>0)
        {
            return abs(num[i]);
        }
        
    }
  
    return 0;
    
}
};