class Solution {
public:
/*0,1  2,3  4,5...etc are related
2 => 10
3 => 11
if 2 is XORed by the last digit with 1...will produce 3, 
that is, if no single component exists within ;)*/
    int singleNonDuplicate(vector<int>& nums) {
        /*int l = 0, r = nums.size()-1, m;
        while(l < r){
            m = (l+r)>>1;
            if(nums[m] != nums[m^1])        
                r = m;
            else
                l = m + 1;
        }
        return nums[l];*/
        if(nums.size() == 1)    return nums[0];
        if(nums[0] != nums[1])  return nums[0];
        if(nums[nums.size()-1] != nums[nums.size()-2])  return nums[nums.size()-1];
        
        int l = 1, r = nums.size()-2, m;
        while(l <= r){
            m = (l+r)>>1;
            if(nums[m] != nums[m-1] && nums[m] != nums[m+1])    return nums[m];
            else if(m % 2 == 1 && nums[m] == nums[m-1] || 
                        m % 2 == 0 && nums[m] == nums[m+1]) 
                    l = m + 1;
            else    r = m - 1;
        }
        return -1;
    }
};