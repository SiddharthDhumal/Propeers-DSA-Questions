#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool withinThreshold(vector<int>& nums,int threshold,int mid){
        long long result = 0;
        for(int i=0;i<nums.size();i++){
            result += ceil((double)nums[i] / mid);
            // result += (nums[i] + mid - 1) / mid;  optimal solution
        }

        return result <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int answer = high;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(withinThreshold(nums,threshold,mid)){
                answer = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return answer;
    }
};