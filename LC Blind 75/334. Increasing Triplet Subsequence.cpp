#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // better approach tc - o(n) and sc - o(n)
    // bool increasingTriplet(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int>leftMin(n,INT_MAX);
    //     vector<int>rightMax(n,INT_MIN);
        
    //     leftMin[0] = nums[0];
    //     rightMax[n-1] = nums[n-1];

    //     for(int i=1;i<n;i++){
    //          leftMin[i] = min(leftMin[i-1],nums[i]);
    //     }

    //     for(int i=n-2;i>=0;i--){
    //          rightMax[i] = max(rightMax[i+1],nums[i]);
    //     }

    //     for(int i=0;i<n;i++){
    //         if(nums[i]>leftMin[i] && nums[i]<rightMax[i])
    //              return true;
    //     }

    //     return false;
    // }



    //optimal approach tc - o(n) and sc - o(1)
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int firstSmallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]<=firstSmallest){
                firstSmallest = nums[i];
            }else if(nums[i]>firstSmallest && nums[i]<=secondSmallest){
                 secondSmallest = nums[i];
            }else{
                return true;
            }
        }

        return false;
    }
};