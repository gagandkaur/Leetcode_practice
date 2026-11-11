class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        long long pairs = min(n1, n2);
        long long cp = pairs * min( cb, c1 + c2);
        long long r1 = n1-pairs;
        long long r2 = n2- pairs;
        long long cr = r1 * min( c1, cb)
                       + r2 * min(c2, cb);
                    
       return cp+ cr;                
    }
};

