class Solution {
public:
    bool recurr(int i, vector<int> &nums, int target, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(target < 0) return false;
        if(i == 0)  return  nums[i] == target;
        if(dp[i][target] != -1) return dp[i][target];
        bool not_pick = recurr(i-1, nums, target, dp);
        bool pick = recurr(i-1, nums, target-nums[i], dp);
        return dp[i][target] = pick || not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i=0; i<nums.size(); ++i){
            target += nums[i];
        }
        if(target%2 != 0)   return false;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return recurr(n-1, nums, target/2, dp);
    }
};