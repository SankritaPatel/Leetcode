class Solution {
public:
    bool checkString(string s) {
        for(int i=0;i<s.size()-1;i++){
            if(s[i]-s[i+1]==1){
                return false;
            }
        }
        return true;
    }
};
