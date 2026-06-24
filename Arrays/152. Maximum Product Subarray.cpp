// TC - O(n) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int maxEndingHere = nums[0];
         int minEndingHere = nums[0];
         int ans = nums[0];

         for(int i =1;i<nums.size();i++){
             int curr = nums[i];

             if(curr<0){
                 swap(maxEndingHere,minEndingHere);
             }

             maxEndingHere = max(curr,curr*maxEndingHere);
             minEndingHere = min(curr,curr*minEndingHere);

             ans = max(ans,maxEndingHere);
         }

         return ans;

    }
};