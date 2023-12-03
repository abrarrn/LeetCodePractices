class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0; i<points.size()-1; ++i){
            int curr_x = points[i][0];
            int curr_y = points[i][1];
            int tar_x = points[i+1][0];
            int tar_y = points[i+1][1];
            ans += max(abs(curr_x-tar_x), abs(curr_y-tar_y));
        }
        return ans;
    }
};