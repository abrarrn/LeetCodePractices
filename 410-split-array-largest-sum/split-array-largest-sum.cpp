class Solution {
public:
    bool satisfies(vector<int>& nums, int k, int num){
        int curr = 0;
        int cnt = 1;
        for(int i=0; i<nums.size(); ++i){
            curr += nums[i];
            if(curr > num){ //current exceeds proposed
                curr = nums[i];
                cnt++;
                if(cnt > k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        int m;
        //every split will at least get the maximum one
        //no split will get more than the summation
        for(int &i: nums){
            l = max(l, i);
            r += i;
        }
        while(l <= r){
            m = (l+r) >> 1;
            if(satisfies(nums, k, m)){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return l; 
    }
};