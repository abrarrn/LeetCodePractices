class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(int i : nums)   
            umap[i]++;
        
        int ans = 0;
        for(auto it=umap.begin(); it!=umap.end(); ++it){
            if(it->second == 1) return -1;
            ans += (it->second/3);
            if(it->second % 3)
                ans++;
        }
        return ans;
    }
};