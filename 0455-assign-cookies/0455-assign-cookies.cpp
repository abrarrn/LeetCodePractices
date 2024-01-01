class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size() == 0)   return 0;   //no cookies, no child satisfied
        int childInd = g.size()-1;
        int cookieInd = s.size()-1;
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(childInd >= 0 && cookieInd >= 0){
            if(s[cookieInd] >= g[childInd]){
                ans++;
                cookieInd--;
            }
            childInd--;
        }
        return ans;
    }
};