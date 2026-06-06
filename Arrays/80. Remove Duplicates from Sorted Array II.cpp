#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if(n<=2) return n;

        int right = 2;

        for(int left = 2;left<n;left++){
             if(nums[left]!=nums[right-2]){
                 nums[right] = nums[left];
                 right++;
             }
        }

        return right;
    }
};