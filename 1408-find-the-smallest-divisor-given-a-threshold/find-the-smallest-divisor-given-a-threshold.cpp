class Solution {
public:
    bool satisfies(vector<int>& nums, int threshold, int num){
        int sum = 0;
        for(int i=0; i<nums.size(); ++i){
            sum += ceil(double(nums[i])/double(num));
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6, m;
        while(l <= r){
            m = (l+r)>>1;
            if(satisfies(nums, threshold, m)){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};