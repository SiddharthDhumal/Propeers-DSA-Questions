#include <bits/stdc++.h>
using namespace std;



// TC - O(n) - where n is the number of nodes in the linked list
// SC - O(1) - no extra space is used

//   Definition for singly-linked list.

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
          if(head==nullptr || head->next==nullptr){
              return nullptr;
          }

          ListNode* slow = head;
          ListNode* fast = head;
          fast = fast->next->next;

          while(fast!=nullptr && fast->next!=nullptr){
               slow = slow->next;
               fast = fast->next->next;
          }

          slow->next = slow->next->next;
          
          return head;
    }
};