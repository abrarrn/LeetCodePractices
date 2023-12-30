class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() == 1)   return true;
        unordered_map<char, int> umap;
        for(string word: words){
            for(char w: word){
                umap[w]++;
            }
        }

        for(auto i: umap){
            if(i.second % words.size()){    //some character occurred greater or smaller times than the word count itself
                return false;
            }
        }
        return true;
    }
};