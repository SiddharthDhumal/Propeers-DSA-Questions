// TC - O(nlog(n)) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
         int n = nums.size();
         sort(nums.begin(),nums.end());
         int largestSideTriangle = 0;

         for(int i=n-1;i>=2;i--){
             int triangleFormed = (nums[i-1]+nums[i-2] > nums[i]) ? (nums[i-1]+nums[i-2] + nums[i]) : 0;

             largestSideTriangle = max(triangleFormed,largestSideTriangle);
         }

         return largestSideTriangle;
    }
};