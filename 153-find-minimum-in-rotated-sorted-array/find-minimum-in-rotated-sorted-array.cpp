/*Intuition: Select the half that has its elements sorted,
pick the minimum amongst them, ignore that part and continue*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)  return nums[0];
        int ans = INT_MAX;
        int l = 0, r = nums.size()-1, m;
        while(l <= r){
            m = (l+r)>>1;
            if(nums[l] <= nums[m]){  //1st half sorted
                ans = min(ans, nums[l]);
                l = m + 1;
            }else{  //2nd half is sorted
                ans = min(ans, nums[m]);
                r = m - 1;
            }
        }
        return ans;
    }
};