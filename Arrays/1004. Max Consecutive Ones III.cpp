// TC - O(n) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
          int zeroes = 0;
          int n = nums.size();
          int left = 0;
          int right = 0;
          int maxLength = INT_MIN;

          while(right<n){

             if(nums[right]==0){
                 zeroes++;
                 while(zeroes>k){
                     if(nums[left]==0) zeroes--;
                     left++;
                 }
             }
             maxLength = max(right-left+1,maxLength);
             right++;   
          }

          return maxLength;
    }
};