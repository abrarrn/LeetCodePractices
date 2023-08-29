class Solution {
public:
    bool satisfies(int num, vector<int>& bloomDay, int m, int k){
        int cnt = 0;
        int buq = 0;
        for(int i=0; i<bloomDay.size(); ++i){
            if(bloomDay[i] <= num){
                cnt++;
            }
            else{
                buq += cnt/k;
                cnt = 0;
            }
        }
        buq += cnt/k;
        return buq >= m;        
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1e5, r = 0, mid;
        if(bloomDay.size() < m*1LL*k*1LL)   //converts int to long long   
            return -1;
        for(int i=0; i<bloomDay.size(); ++i){
            l = min(bloomDay[i], l);
            r = max(bloomDay[i], r);
        }      
        while(l <= r){
            mid = (l+r)>>1;
            if(satisfies(mid, bloomDay, m, k)){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};