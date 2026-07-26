#include <bits/stdc++.h>
using namespace std;

// Time Complexity

// Let n = s.length().

// Each pointer moves from one end of the string toward the other at most once.

// left moves at most n times.
// right moves at most n times.

// Even though there are nested while loops, the pointers never move backward.

// Therefore,

// Time Complexity: O(n)

// Space Complexity

// We modify the string in place.

// Only a few variables are used:

// left
// right

// No extra array, vector, or string is created.

// Space Complexity: O(1)

// Summary
// Approach	Time	Space
// Two Pointers	O(n)	O(1)


class Solution {
private:
    bool isVowel(char ch){
        ch = tolower(ch);

        return ch == 'a' ||
               ch == 'e' ||
               ch == 'i' ||
               ch == 'o' ||
               ch == 'u';
    }
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left<right){
            
            while(left<right and !isVowel(s[left]))
                  left++;
            
            while(right>left and !isVowel(s[right]))
                  right--;
            
            swap(s[left],s[right]);

            left++;
            right--;
        }

        return s;
    }
};