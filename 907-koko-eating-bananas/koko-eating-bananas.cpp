class Solution {
public:
    bool satisfies(vector<int>& piles, int num, int h){
        double temp = 0;
        for(int i=0; i<piles.size(); ++i){
            temp += ceil(double(piles[i])/double(num));
        }
        return temp <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, r = 0, m, ans;
        for(int i=0; i<piles.size(); ++i){
            r = max(r, piles[i]);
        }
        if(h == piles.size())   return r;

        while(l <= r){
            m = (l+r)>>1;
            if(satisfies(piles, m, h)){
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return l;
        /*
        l ~ r denotes the range for which the answer is true
        we tend to modify this range using binary search
        at some point: l and r are side by side or in the same. 
        satisfies() is true for m and r gets behind of the range
        l is the only one left of that range and thus is our answer
        */
    }
};