class Solution {
public:
    int numJewelsInStones(string jw, string s) {
       int count =0;
       for ( int i =0;i<s.length(); i++){
        for ( int j = 0; j<jw.length(); j++){
            if(s[i]==jw[j]){
                count ++;
                break;
            }
        }
       }
       return count;
    }
};