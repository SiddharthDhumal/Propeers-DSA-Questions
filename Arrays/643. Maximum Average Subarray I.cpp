// TC - O(n) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
         double answer = 0.0;

         int left = 0;
         int right = right = 0;
         int sum = 0;
         double maxAvg = INT_MIN;
         while(right<nums.size()){
             sum += nums[right];
             
             while(right-left+1 > k){
                   sum -= nums[left];
                   left++;
             }
             
             if(right-left+1==k){
                maxAvg  = max((double) sum/k,maxAvg);
             }
             right++;
         }

         return maxAvg;
         
    }
};