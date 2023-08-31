class Solution {
public:
    bool satisfies(int num, vector<int>& weights, int days){
        int sum = 0, cnt = 0;
        for(int i=0; i<weights.size(); ++i){
            sum += weights[i];
            if(sum > num){
                cnt++;
                sum = weights[i];
            }
        }
        cnt++;
        return cnt <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=0, r=0, m;
        for(int &i : weights){
            l = max(l, i);
            r += i;
        }
        while(l <= r){
            m = (l+r)>>1;
            if(satisfies(m, weights, days)){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};