// Find Local Minimum                                      Medium

// Acceptance: 45%

// Given an array nums of distinct integers, find a local minimum element and return its index.

// An element nums[i] is a local minimum if it is smaller than its neighbors. For the elements at the boundaries, we consider only one neighbor.

// You may assume nums[-1] = nums[n] = +∞ (infinity).

// Return the index of any local minimum.

// Example 1: Input: nums = [1,2,3,4,5] Output: 0 Explanation: The first element is a local minimum since it is smaller than its only neighbor.

// Example 2: Input: nums = [5,4,3,2,1] Output: 4 Explanation: The last element is a local minimum since it is smaller than its only neighbor.

// Example 3: Input: nums = [9,6,3,14,5,7,4] Output: 2 Explanation: nums[2] = 3 is a local minimum since it is smaller than nums[1] = 6 and nums[3] = 14.

// Examples:
// Example 1:

// Input:
// nums = [1,2,3,4,5]

// Output:
// 0

// Explanation:
// The first element is a local minimum since it is smaller than its only neighbor.

// Example 2:

// Input:
// nums = [5,4,3,2,1]

// Output:
// 4

// Explanation:
// The last element is a local minimum since it is smaller than its only neighbor.

// Example 3:

// Input:
// nums = [9,6,3,14,5,7,4]

// Output:
// 2

// Explanation:
// nums[2] = 3 is a local minimum since it is smaller than nums[1] = 6 and nums[3] = 14.

// Constraints:
// 1 <= nums.length <= 10^5
// All elements in nums are distinct














// Solution : TC - O(log(n)) and SC - O(1)

#include "bits/stdc++.h"
using namespace std;

// Note : -
// - Modify the function or parameters if needed.
// - Signatures function may vary, adjust parameters if required.

class Solution {
public:
    int findLocalMinimum(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;

        int low = 0;
        int high = n - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};





