class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)  return nums[0];
        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);
        if(nums.size()==2)  return prev1;
        for(int i=2; i<nums.size(); ++i){
            int res = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = res;
        }
        return prev1;
    }
};