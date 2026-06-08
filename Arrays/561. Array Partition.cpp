// TC - O(nlog(n)) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int maxSum = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        

        for(int i=0;i<n-1;i+=2){
             maxSum += nums[i];
        }

        return maxSum;
    }
};