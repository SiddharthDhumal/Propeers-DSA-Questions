#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC - O(n) and SC - O(n) better approach
    // int pivotIndex(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>leftPrefixSum(n);
    //     vector<int>rightPrefixSum(n);
    //     leftPrefixSum[0] = nums[0];
    //     rightPrefixSum[n-1] = nums[n-1];

    //     for(int i=1;i<n;i++){
    //         leftPrefixSum[i] = nums[i] + leftPrefixSum[i-1]; 
    //     }

    //     for(int i=n-2;i>=0;i--){
    //         rightPrefixSum[i] = nums[i] + rightPrefixSum[i+1];
    //     }

    //     for(int i=0;i<n;i++){
    //          if(leftPrefixSum[i]==rightPrefixSum[i]) return i;
    //     }

    //     return -1;
    // }

    // TC - O(n) and SC - O(1) optimal approach
    int pivotIndex(vector<int>& nums) {
          int totalSum = 0;
          int leftSum = 0;
          int n = nums.size();

          for(int i=0;i<n;i++){
             totalSum += nums[i];
          }

          for(int i=0;i<n;i++){
             if(totalSum - leftSum - nums[i] == leftSum) return i;
             leftSum += nums[i];
          }

          return -1;
          
    }
};