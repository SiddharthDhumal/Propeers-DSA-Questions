#include <bits/stdc++.h>
using namespace std;


// Time Complexity

// You scan the array only once.

// Time Complexity: O(m) (or O(n) if n denotes the array length)
// Space Complexity

// You only use a few variables:

// m
// i
// leftEmpty
// rightEmpty

// No extra array or data structure is created.

// Space Complexity: O(1)

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int m = flowerbed.size();

        for (int i = 0; i < m; i++) {

            if (flowerbed[i] == 0) {

                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == m - 1) || (flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1;
                    n--;
                }
            }

            if (n <= 0)
                return true;
        }

        return false;
    }
};