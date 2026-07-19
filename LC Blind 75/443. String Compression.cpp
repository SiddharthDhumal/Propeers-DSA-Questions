#include <bits/stdc++.h>
using namespace std;

// TC - O(n) and SC - O(1)
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int read = 0;
        int write = 0;

        while (read < n) {
            char currentChar = chars[read];
            int cnt = 0;

            while (read < n && chars[read] == currentChar) {
                read++;
                cnt++;
            }

            chars[write] = currentChar;
            write++;

            if (cnt > 1) {
                string freq = to_string(cnt);
                for (char digit : freq) {
                    chars[write] = digit;
                    write++;
                }
            }
        }

        return write;
    }
};