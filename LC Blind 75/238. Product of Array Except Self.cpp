#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
     // better approach TC - O(n) and SC - O(n)
    //  vector<int> productExceptSelf(vector<int>& nums) {

    //     int n = nums.size();

    //     vector<int> prefix(n);
    //     vector<int> suffix(n);
    //     vector<int> answer(n);

    //     // Build prefix array
    //     prefix[0] = 1;
    //     for(int i = 1; i < n; i++) {
    //         prefix[i] = prefix[i - 1] * nums[i - 1];
    //     }

    //     // Build suffix array
    //     suffix[n - 1] = 1;
    //     for(int i = n - 2; i >= 0; i--) {
    //         suffix[i] = suffix[i + 1] * nums[i + 1];
    //     }

    //     // Build answer
    //     for(int i = 0; i < n; i++) {
    //         answer[i] = prefix[i] * suffix[i];
    //     }

    //     return answer;
    // }


    // optimal approach TC - O(n) and SC - O(1)
    vector<int> productExceptSelf(vector<int>& nums) {
         int n = nums.size();
         vector<int>answer(n,1);

         long long left_product = 1;
         for(int i=0;i<n;i++){
             answer[i] = (int)left_product;
             left_product *= nums[i];
         }

         long long right_product = 1;
         for(int i=n-1;i>=0;i--){
             answer[i] *= (int) right_product;
             right_product *= nums[i];
         }

         return answer;
    }
};