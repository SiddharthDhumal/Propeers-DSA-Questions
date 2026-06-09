#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // k = maximum number of digits in a number , n = nums.size()
    // TC - O(nlogn⋅k) and SC - O(nk)
    
    static bool comp(string a,string b){
         return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;

        for(auto num:nums){
             arr.push_back(to_string(num));
        }

        sort(arr.begin(),arr.end(),comp);
        
        if(arr[0]=="0") return "0";

        string result = "";

        for(string& s:arr){
            result += s;
        }
        
        return result;
    }
};




// This gets to the heart of how **sorting algorithms** work.

// You're thinking:

// > "I already compared `3` and `30`. Why do I need to compare `3` and `34` again?"

// Because sorting is trying to determine the **relative ordering of every element**, not just one pair.

// ---

// ### Imagine three elements

// ```text
// 3, 30, 34
// ```

// From the first comparison, we learn:

// ```text
// 3 should come before 30
// ```

// So we know:

// ```text
// 3 > 30   (according to our custom ordering)
// ```

// But do we know where `34` belongs?

// No.

// We still need to determine:

// ```text
// 34 vs 3
// 34 vs 30
// ```

// ---

// ### Think of it as a tournament

// Suppose we have players:

// ```text
// A = 3
// B = 30
// C = 34
// ```

// You played:

// ```text
// A vs B
// ```

// and found:

// ```text
// A wins
// ```

// Can you conclude whether:

// ```text
// A beats C ?
// ```

// No.

// You must actually compare:

// ```text
// A vs C
// ```

// ---

// ### Let's do the actual comparisons

// We already know:

// #### 3 vs 30

// ```text
// 330
// 303
// ```

// Therefore:

// ```text
// 3 before 30
// ```

// ---

// Now compare:

// #### 34 vs 3

// ```text
// 343
// 334
// ```

// Therefore:

// ```text
// 34 before 3
// ```

// This is brand new information.

// Now our ordering becomes:

// ```text
// 34, 3, 30
// ```

// ---

// ### What sort is really doing

// The sorting algorithm is repeatedly asking:

// > "Given two elements, which should come first?"

// Your comparator answers that question.

// The sorting algorithm itself decides **which pairs need to be compared**.

// For example:

// ```cpp
// sort(arr.begin(), arr.end(), comp);
// ```

// might internally call:

// ```cpp
// comp("3", "30");
// comp("34", "3");
// comp("34", "30");
// comp("5", "34");
// ...
// ```

// You don't control these comparisons.

// The sorting algorithm does.

// ---

// ### A common misconception

// Many people think:

// ```text
// If I compare every element once, sorting is done.
// ```

// Not true.

// For:

// ```text
// [9, 5, 34, 3, 30]
// ```

// you need enough pairwise information to establish a complete order.

// Just knowing:

// ```text
// 3 before 30
// ```

// doesn't tell you whether:

// ```text
// 34 before 3
// or
// 3 before 34
// ```

// ---

// ### Interview-level understanding

// Your comparator defines a rule:

// ```cpp
// a + b > b + a
// ```

// The STL sort then uses that rule to build a complete ordering of all elements.

// You don't need to manually think:

// > Compare 3 with 30, then 3 with 34, then ...

// The sorting algorithm handles that.

// Your responsibility is only:

// > Given any two elements `a` and `b`, tell me which one should come first.

// That's exactly what the comparator does.
