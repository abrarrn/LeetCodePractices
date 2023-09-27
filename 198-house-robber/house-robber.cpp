class Solution {
private:
    int recurr(vector<int>& nums, int i, vector<int>& dp){
        if(i == 0)      return nums[i];
        if(i < 0)       return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + recurr(nums, i - 2, dp);
        int notPick = recurr(nums, i - 1, dp);
        return dp[i] = max(pick, notPick);
    }
public:
    int rob(vector<int>& nums) {
        vector<int> dp(100, -1);
        return recurr(nums, nums.size()-1, dp);
    }
};