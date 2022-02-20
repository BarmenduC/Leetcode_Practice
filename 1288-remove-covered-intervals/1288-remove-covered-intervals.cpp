class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n=in.size();
        int c1=1;//one for a and b;
        int a=in[0][0],b=in[0][1];
        for(int i=1;i<n;i++){
            if(in[i][0]>a&&in[i][1]>b)
                c1++;
            if(in[i][1]>b){//here removing the covered part
                a=in[i][0];
                b=in[i][1];
               }
            }
        return c1;
        
    }
};