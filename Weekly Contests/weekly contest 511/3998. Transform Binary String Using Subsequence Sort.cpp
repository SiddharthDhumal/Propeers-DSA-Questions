#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int count(string str, char value) {
        int count = 0;
        for (char c : str) {
            if (c == value)
                count++;
        }

        return count;
    }

public:
    // https://youtu.be/1UR7BByg2Kw?si=UVTddy85qis9hNVg

    // TC - O(n*m) where n = s.length and m = strs.size
    // SC - O(1)
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n = s.size();
        int zero_s = count(s, '0');
        int one_s = count(s, '1');

        vector<bool> res;

        for (string str : strs) {
            int zero_str = count(str, '0');
            int one_str = count(str, '1');

            int diff_0 = zero_s - zero_str;
            int diff_1 = one_s - one_str;

            // Step-1: Check availability of values 0s and 1s
            if (diff_0 < 0 || diff_1 < 0) {
                res.push_back(false);
                continue;
            }

            // Step-2: Balance Greedily: Leftmost '?' using diff_0
            // Because 0s can move only from right to left while sorting
            for (int i = 0; i < n and diff_0 > 0; i++) {
                if (str[i] == '?') {
                    str[i] = '0';
                    diff_0--;
                }
            }

            // Step-3: Balance Greedily: Rightmost '?' using diff_1
            // Because 1s can move from left to right while sorting
            for (int i = n - 1; i >= 0 && diff_1 > 0; i--) {
                if (str[i] == '?') {
                    str[i] = '1';
                    diff_1--;
                }
            }

            // Check if Greedy assignment of 1s breaks rule
            int s_one_idx = 0;
            int str_one_idx = 0;
            bool solved = true;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    s_one_idx++;
                if (str[i] == '1')
                    str_one_idx++;

                if (str_one_idx > s_one_idx) {
                    solved = false;
                    break;
                }
            }

            res.push_back(solved);
        }

        return res;
    }
};