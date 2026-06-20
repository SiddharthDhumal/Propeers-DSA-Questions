#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        if (firstList.empty() || secondList.empty())
            return {};

        vector<vector<int>> answer;

        int m = firstList.size();
        int n = secondList.size();

        int i = 0, j = 0;

        while (i < m && j < n) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);
            if (start <= end) {
                answer.push_back({start, end});
            }

            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }

        return answer;
    }
};