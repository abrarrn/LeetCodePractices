class Solution {
public:
    string largestGoodInteger(string num) {
        int large_num = -1;
        int starts_from = -1;
        for(int i=0; i<num.length()-2; ++i){
            if((num[i] == num[i+1]) && (num[i] == num[i+2])){
                if(large_num < num[i]-'0'){
                    large_num = num[i]-'0';
                    starts_from = i;
                }
                i += 2;
            }
        }
        if(large_num == -1) return "";
        return num.substr(starts_from,3);
    }
};