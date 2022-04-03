class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
     int k1;
    if(nums.size()==1)return ;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            k1=i;
            break;
        }
    }
    if(k1<0){
        reverse(nums.begin(),nums.end());
    }
    else{
        int k2=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[k1]){
                k2=i;
                break;
            }
        }
        swap(nums[k1],nums[k2]);
        reverse(nums.begin()+k1+1,nums.end());
        
    }
}
};