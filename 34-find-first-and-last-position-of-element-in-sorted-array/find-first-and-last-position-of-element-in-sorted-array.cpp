class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if(nums.size() == 0)                
            return ans;
        if(target < nums[0] || nums[nums.size()-1] < target)    //target is out of range                
            return ans;
        auto it = lower_bound(nums.begin(), nums.end(), target);
        if(*it == target){  //target is available
            ans[0] = it - nums.begin();
            auto it = upper_bound(nums.begin(), nums.end(), target);
            ans[1] = it - nums.begin() - 1;
        }
        return ans;
    }   
};