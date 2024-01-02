class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int num : nums){
            umap[num]++;
        }
        vector<vector<int>> ans;
        while(!umap.empty()){
            vector<int> temp;
            for(auto it = umap.begin(); it != umap.end(); ){
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0){
                    it = umap.erase(it);    //new context
                }else{
                    ++it;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};