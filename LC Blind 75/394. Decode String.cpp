#include <bits/stdc++.h>
using namespace std;



// Optimal Approach (Using Two Stacks)
// Time Complexity: O(n + m)

// Where:

// n = length of the input string
// m = length of the decoded output string

// Why?

// We scan the input string once → O(n)
// While decoding, we build the output string. Every character that appears in the final answer is appended exactly once → O(m)

// So,

// O(n) + O(m) = O(n + m)
// Space Complexity: O(n + m)

// Why?

// The two stacks store information about nested brackets → at most O(n)
// The decoded output string stores m characters → O(m)

// So,

// O(n) + O(m) = O(n + m)
// Easy Interview Answer
// Time Complexity: O(n + m) because we traverse the input once and generate each character of the decoded string exactly once.
// Space Complexity: O(n + m) because we use two stacks (O(n)) and store the decoded output (O(m)).
// One-line trick to remember

// Input traversal costs O(n), output generation costs O(m). Therefore, both time and space are O(n + m).

class Solution {
public:
    string decodeString(string s) {
        stack<int>countStack;
        stack<string>stringStack;

        string current = "";
        int number = 0;


        for(char ch:s){
            // Build multi-digit number
            if(isdigit(ch)){
                 number = number * 10 + (ch-'0');
            }
            // Start of a new encoded string
            else if(ch=='['){
                countStack.push(number);
                stringStack.push(current);

                number = 0;
                current = "";
            }
            // End of current encoded string
            else if(ch==']'){
                int repeat = countStack.top();
                countStack.pop();
                string previous = stringStack.top();
                stringStack.pop();

                while(repeat--){
                    previous += current;
                }

                current = previous;
            }else{
                current += ch;
            }
        }

        return current;
    }
};