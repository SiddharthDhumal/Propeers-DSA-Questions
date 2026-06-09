// TC - O(nlog(n)) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
          int n = nums.size();
          
          if(n==1) return 0;
          int minimizedAns = INT_MAX;
          
          sort(nums.begin(),nums.end());

          for(int i=0;i<=n-k;i++){
              minimizedAns = min(nums[i+k-1]-nums[i],minimizedAns);
          }

          return minimizedAns;
    }
};