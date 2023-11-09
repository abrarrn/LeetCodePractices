class Solution {
public:
    int countHomogenous(string s) {
        vector<long long> vec(26, 0);
        int l=0, r=0;
        for(int i=0; i<s.length(); ++i){
            if(s[l] != s[r]){   //if the characters are not equal
                l = r;
            }
            vec[s[l]-'a'] += (r-l+1);
            r++;
        }
        long long ans = 0;
        for(auto i : vec){
            ans += i;
        }
        return (int)(ans % 1000000007);
    }
};