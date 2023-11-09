class Solution {
public:
    float getSlope(vector<int>& pointsi, vector<int>& pointsj){
        if(pointsi[0] == pointsj[0])    //x1 == x2
            return 90;
        //(y2-y1)/(x2-x1)
        return float(pointsj[1]-pointsi[1])/(pointsj[0]-pointsi[0]);
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0; i<points.size()-1; ++i)
        {
            float slope;
            unordered_map<float, int> slopes;
            for(int j=i+1; j<points.size(); ++j)
            {
                slope = getSlope(points[i], points[j]);
                slopes[slope]++;
                ans = max(ans, slopes[slope]);
            }
        }
        
        return ans+1;
    }
};