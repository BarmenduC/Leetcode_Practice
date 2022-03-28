class Solution {
public:
    bool search(vector<int>& nums, int target) {
        size_t n = nums.size();
        int low = 0;
        int high = n - 1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums.at(mid) == target){
                return true;
            }
            if((nums.at(mid) == nums.at(high)) && (nums.at(low) == nums.at(mid))){// shrink the search partition as it would affect array
                low++; high--;
            }else if(nums.at(mid) <= nums.at(high)){ // right sorted
               if(target>=nums.at(mid) && target<=nums.at(high)){
                   low = mid + 1;
               }else{
                   high = mid - 1;
               }
            }else{//if right not sorted then left must be sorted
                if(target>=nums.at(low) && target<=nums.at(mid)){
                    high = mid - 1;
                }else{
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};