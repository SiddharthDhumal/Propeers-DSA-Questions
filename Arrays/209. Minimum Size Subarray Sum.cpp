#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minimumLength = INT_MAX;
        int left = 0;
        int right = 0;
        
        int sum = 0;

        while(right<nums.size()){
            sum += nums[right];
            
            while(sum>=target){
                minimumLength = min(right-left+1,minimumLength);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        return minimumLength==INT_MAX ? 0 : minimumLength;
    }
};