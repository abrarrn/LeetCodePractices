class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = 0;

        for(int i=0; i<r; ++i){
            for(int j=0; j<c; ++j){
                if(matrix[i][j] != 0 && i > 0){   //if multiple rows exists
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            vector<int> curr_row = matrix[i];
            sort(curr_row.begin(), curr_row.end(), greater());
            for(int i=0; i<c; ++i){
                ans = max(ans, curr_row[i]*(i+1));
            }
        }

        return ans;
    }
};