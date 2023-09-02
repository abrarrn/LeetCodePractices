class Solution {
public:
    bool satisfies(vector<int>& position, int m, int num){
        int cnt = 1;
        int curr = position[0];
        for(int i=1; i<position.size(); ++i){
            if(position[i]-curr >= num){
                curr = position[i];
                cnt++;
                if(cnt == m)    break;
            }
        }
        return cnt == m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        if(m == 2)  return position[position.size()-1] - position[0];
        /*if(m == position.size()){
            int ans = INT_MAX;
            for(int i=0; i<m-1; ++i){
                ans = min(ans, position[i+1]-position[i]);
            }
            return ans;
        }*/
        int l = 0;
        int r = position[position.size()-1] - position[0];
        while(l <= r){
            int mid = (l+r)>>1;
            if(satisfies(position, m, mid)){
                l = mid + 1;
            }else{
                r = mid - 1;
            }    
        }
        return r;
    }
};