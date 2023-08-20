class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target < nums[0])                return 0;
        if(nums[nums.size()-1] < target)    return nums.size();
        auto it = upper_bound(nums.begin(), nums.end(), target);
        return nums[it - nums.begin() - 1] == target ? it - nums.begin() - 1 : it - nums.begin();
    }
};