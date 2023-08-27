class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1)  return x;
        int l = 1, r = x;
        long long m;
        while(l <= r){
            m = l+(r-l)/2;
            if(m*m <= x)    l=m+1;
            else r=m-1;
        }
        return r;
    }
};