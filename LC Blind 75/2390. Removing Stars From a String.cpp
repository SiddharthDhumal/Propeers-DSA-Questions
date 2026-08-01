#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // better approach TC - O(n) SC - O(n)
    // string removeStars(string s) {
    //     stack<char>st;

    //     for(int i=0;i<s.size();i++){
    //         st.push(s[i]);
    //     }

    //     string ans = "";
    //     int cnt = 0;
    //     while(!st.empty()){
    //         char top = st.top();
    //         st.pop();
    //         if(top=='*') cnt++;
    //         else if(cnt==0) ans += top;
    //         else cnt--;
    //     }

    //     reverse(ans.begin(),ans.end());

    //     return ans;
    // }

    
    // Optimal approach TC - O(n) SC - O(1)
    string removeStars(string s) {
      string ans = "";

       for(char ch:s){
         if(ch=='*') ans.pop_back();
         else ans.push_back(ch);
       }

       return ans;
    }
};