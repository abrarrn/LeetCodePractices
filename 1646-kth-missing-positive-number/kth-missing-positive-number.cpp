class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size()-1, m;
        while(l <= r){
            m = (l+r)>>1;
            if(arr[m]-m-1 < k){
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        /*l is pointing towards the index 
        whose value is higher than the missing number*/
        return l+k;
    }
};