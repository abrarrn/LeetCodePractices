class Solution {
public:
    int climbStairs(int n) {
        //you can reach in your current stair from one-step back or two-steps back
        if(n == 0)  return 1;
        if(n == 1)  return 1;
        int ways = 0, step_1_back = 1, step_2_back = 1;
        for(int i=2; i<=n; ++i){
            ways = step_1_back + step_2_back;
            step_1_back = step_2_back;
            step_2_back = ways;
        } 
        return ways;
    }
};