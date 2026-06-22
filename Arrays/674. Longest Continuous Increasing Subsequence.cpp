// TC - O(n) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
          int left = 0;
          int right = 1;
          int longestSubArray = INT_MIN;

          while(right<nums.size()){
              if(nums[right]>nums[right-1]){
                    longestSubArray = max(right-left+1,longestSubArray);
              }else{
                  left = right;
              }

              right++;
          }

          return longestSubArray==INT_MIN ? 1 : longestSubArray;
    }
};