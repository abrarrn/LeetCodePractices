class Solution {
public:
    pair<int, int> countCurr(string s){
        int zeros = 0, ones = 0;
        for(char &ch : s){
            if(ch == '0')   zeros++;
            else ones++;
        }
        return make_pair(zeros, ones);
    }
    
    int recurr(int i, vector<string>& strs, int remZeros, int remOnes, vector<vector<vector<int>>> &dp){
        //base-cases
        if(i < 0 || remZeros < 0 || remOnes < 0){
            return 0;
        }
        if(dp[i][remZeros][remOnes] != -1) return dp[i][remZeros][remOnes];
        
        pair<int, int> curr = countCurr(strs[i]);
        int curr_zeros = curr.first;
        int curr_ones =  curr.second;
        int not_pick = recurr(i-1, strs, remZeros, remOnes, dp);
        int pick = 0;
        if(curr_ones <= remOnes && curr_zeros <= remZeros){
            //there are at most m 0's and n 1's in the subset...
            pick = 1 + recurr(i-1, strs, remZeros-curr_zeros, remOnes-curr_ones, dp);    
        }
        return dp[i][remZeros][remOnes] = max(pick, not_pick);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int remZeros = m, remOnes = n;
        
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        return recurr(strs.size()-1, strs, remZeros, remOnes, dp);
    }
};