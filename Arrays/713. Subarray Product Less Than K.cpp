// TC - O(n) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
          int n = nums.size();
          if(k==0 || k==1) return 0;
          int op = 0;
          int left = 0;
          int product = 1 ;
          int right = 0;
          
          while(right<n){
             product *= nums[right];
          
             while(product>=k){
                 product /= nums[left];
                 left++;
             }

             op += right-left+1;

             right++;
          }


          return op;
    }
};