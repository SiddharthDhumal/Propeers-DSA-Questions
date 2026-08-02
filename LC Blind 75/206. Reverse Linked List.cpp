#include <bits/stdc++.h>
using namespace std;

// * Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    // Brute Force approach
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* temp = head;
    //     stack<int> st;
    //     while(temp!=nullptr){
    //         st.push(temp->val);
    //         temp = temp->next;
    //     }

    //     temp = head;

    //     while(temp!=nullptr){
    //         temp->val = st.top();
    //         st.pop();
    //         temp = temp->next;
    //     }

    //     return head;
    // }

    //Optimal Approach 1 (Iterative Approach)
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = head;
//         ListNode* prev = nullptr;

//           while(temp != NULL){  
//        // Store the next node in
//        // 'front' to preserve the reference
//        ListNode* front = temp->next;  
       
//        // Reverse the direction of the
//        // current node's 'next' pointer
//        // to point to 'prev'
//        temp->next = prev;  
       
//         // Move 'prev' to the current
//         // node for the next iteration
//        prev = temp;  
       
//         // Move 'temp' to the 'front' node
//         // advancing the traversal
//        temp = front; 
//    }


//         return prev;
//     }

 // Optimal Approach (Recursive Approach)

    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next == nullptr){
            return head;
        }

        ListNode* newHead = reverseList(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;

        return newHead;
    }
 
};