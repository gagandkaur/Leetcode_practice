class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        
        sort ( nums.begin(), nums.end());
        unordered_map<int, int > m;
         
         int ans =0;

         for ( int x: nums){
            m[x+1] = max(m[x+1] , m[x]+1);
            m[x] = max(m[x] , m[x-1]+1);
             ans = max({ ans, m[x] , m[x+1]});
            
         }
         return ans;
    }
};
// Input : 2,1,5,1,1
//modify : 3,2,5,1,1
//sort :1,1,2,3,5
//consecutive: 1,2,3