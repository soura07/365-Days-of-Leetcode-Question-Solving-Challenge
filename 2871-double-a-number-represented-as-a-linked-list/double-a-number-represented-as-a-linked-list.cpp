/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        stack<int> s;
        ListNode* temp = head;
        while (temp != nullptr) {
            s.push(temp->val);
            temp = temp->next;
        }
        int num {};
        ListNode* tail = nullptr;
        while (!s.empty() || num != 0) {
            tail = new ListNode(0, tail);
            if (!s.empty()) {
                num += s.top() * 2;
                s.pop();

            }
            tail->val = num % 10;
            num /= 10;
        }
        return tail;
    }
};