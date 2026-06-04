#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
          int answer = nums[0] + nums[1] + nums[2];
          int n = nums.size();

          sort(nums.begin(),nums.end());

          for(int i=0;i<n-2;i++){
               int j = i+1;
               int k = n-1;
               while(j<k){
                  int totalSum = nums[i] + nums[j] + nums[k];
                  if (abs(totalSum - target) < abs(answer - target)) {
                     answer = totalSum;
                  }

                  if(totalSum==target){
                      return totalSum;
                  }
                  else if(totalSum>target){
                     k--;
                  }else{
                     j++;
                  }
               }
          }

          return answer;

    }
};