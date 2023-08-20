class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, m;
        while(l < r){
            m = (l + r) >> 1;
            if(nums[m] == target)       return true;
            else if(nums[l] == target)  return true;
            else if(nums[r] == target)  return true;
            else if(nums[l] == nums[m] && nums[m] == nums[r]){
                //trim down the search space
                l = l + 1, r = r - 1;
            }
            else if(nums[m] <= nums[r]){ //normal flow...2nd half is ascending
                if(nums[m] < target && target < nums[r]){   //target is in 2nd half
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
            else{ //abnormal flow...1st half is ascending
                if(nums[l] < target && target < nums[m]){   //target is in 1st half
                    r = m - 1;
                }
                else{
                    l = m + 1;
                }
            }
        }
        return nums[m] == target ? true : false; 
    }
};