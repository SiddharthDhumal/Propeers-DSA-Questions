#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int maximumProduct = INT_MIN;
        sort(nums.begin(),nums.end());

        maximumProduct = max((nums[0]*nums[1]*nums[2]),(nums[n-1]*nums[n-2]*nums[n-3]));

        maximumProduct = max((nums[0]*nums[1]*nums[n-1]),maximumProduct);

        return maximumProduct;
    }
};