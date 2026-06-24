// TC - O(2*n) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;
        int pivot = -1;
        int n = nums.size();

        for(int i=0;i<n;i++){
             totalSum += nums[i];
        }

        for(int i = 0;i<n;i++){
            if(totalSum - leftSum - nums[i] == leftSum){
                 return i;
            }

            leftSum += nums[i];
        }
        
        return pivot;
    }
};