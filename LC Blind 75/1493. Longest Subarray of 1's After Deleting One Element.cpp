#include <bits/stdc++.h>
using namespace std;


// TC - O(n) and SC - O(1)
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int deletionEle = 0;
        int maxLength = 0;

        while(right<n){
            if(nums[right]==0) deletionEle++;
            while(deletionEle>1){
                if(nums[left]==0) deletionEle--;
                left++;
            }

            maxLength = max(right-left+1-deletionEle, maxLength);
            right++;
        }

        if(deletionEle==0) maxLength -= 1;

        return maxLength;
    }
};